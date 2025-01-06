#include "PmergeMe.hpp"

// Canonical Orthodox Form

PmergeMe::PmergeMe(void)
{
	throw std::runtime_error("No arguments are given!");
}

PmergeMe::PmergeMe(std::string* args, int size)
{
	// Parse and initialize the two containers
	for(int i = 0; i < size; i++)
		parse_push(args[i]);

	// Display vector container unsorted
	std::cout << GREEN << "Before: " << RESET;
	for(std::vector<int>::iterator itv1 = vec.begin(); itv1 != vec.end(); itv1++)
		std::cout << *itv1 << " ";
	std::cout << std::endl;

	// Executes the sort algorithm for the vector and measures the time elapsed
	clock_t	start_v = clock();
	ford_johnson_vec(vec, 2);
	clock_t	end_v = clock();
	double	diff_vec = static_cast<double>(end_v - start_v) / CLOCKS_PER_SEC * 1000000;

	// Display vector container sorted
	std::cout << GREEN << "After:  " << RESET;
	for(std::vector<int>::iterator itv2 = vec.begin(); itv2 != vec.end(); itv2++)
		std::cout << *itv2 << " ";
	std::cout << std::endl;

	// Executes the sort algorithm for the list and measures the time elapsed
	clock_t	start_l = clock();
	ford_johnson_deque(deque, 2);
	clock_t	end_l = clock();
	double	diff_list = static_cast<double>(end_l - start_l) / CLOCKS_PER_SEC * 1000000;

	// Display the time taken by the algorithm with the vector
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector<int> : " << diff_vec << " us" << std::endl;

	// Display the time taken by the algorithm with the list
	std::cout << "Time to process a range of " << deque.size() << " elements with std::deque<int>  : " << diff_list << " us" << std::endl;

}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &src)
{
	if (this != &src)
	{
		this->deque = src.deque;
		this->vec = src.vec;
	}
	return (*this);
}

// Parsing

/*Parse the input and insert unsorted numbers on each container*/
void	PmergeMe::parse_push(std::string input)
{
	std::stringstream	sinput;
	long				nb;

	if (!is_integer(input))
		throw std::runtime_error("Error: " + input + " is not an integer");
	sinput << input;
	sinput >> nb;
	if (nb < 0)
		throw std::runtime_error("Error: " + input + " is a negative integer");
	if (nb > 2147483647)
		throw std::runtime_error("Error: " + input + " overflows int type capacity");
	vec.push_back(nb);
	deque.push_back(nb);
}

bool	PmergeMe::is_integer(std::string str)
{
	std::string::iterator it = str.begin();
	if (*it == '0' && str.length() > 1)
		throw std::runtime_error("Error: " + str + " is in wrong format");
	else if (*it == '-')
		it++;
	for(; it != str.end(); it++)
	{
		if (*it < '0' || *it > '9')
			return (false);
	}
	return (true);
}

// Sort algorithm utils

/*Gives the nth number of the jacobsthal series, used in the ford johnson sort
It start with an offset of two: 3, 5, 11, 21, 43, 85, 171, ...*/
long		PmergeMe::jacobsthal(long n)
{
	return ((pow(2, n + 3) - pow(-1, n + 1)) / 3);
}

// Ford-Johnson Algorithm with vector container

void	PmergeMe::swap(std::vector<int> &tabv, int begin, int step)
{
	std::vector<int> temp;
	temp.insert(temp.begin(), tabv.begin() + begin, tabv.begin() + begin + (step / 2));
	
	for (int i = begin; i < begin + (step / 2); i++)
		tabv[i] = tabv[i + (step / 2)]; 
	for (int i = begin + (step / 2); i < begin + step; i++)
		tabv[i] = temp[i - (begin + (step / 2))];
}

void	PmergeMe::binary_insertion(std::vector<int> &tab, int tab_idx, std::vector<int> &nb, int idx_nb, int pair)
{
	while (tab_idx >= 0 && tab[tab_idx] > nb[idx_nb])
		tab_idx -= pair / 2;
	if (tab_idx < 0)
		tab.insert(tab.begin(), nb.begin() + idx_nb - (pair / 2) + 1, nb.begin() + idx_nb + 1);
	else
		tab.insert(tab.begin() + tab_idx + 1, nb.begin() + idx_nb - (pair / 2) + 1, nb.begin() + idx_nb + 1);
	nb.erase(nb.begin() + idx_nb - (pair / 2) + 1, nb.begin() + idx_nb + 1);
}

bool PmergeMe::is_sorted(std::vector<int> tabv, int begin, int step)
{
	int max_left = get_max(tabv, begin, begin + step / 2);
	int max_right = get_max(tabv, begin + (step / 2), begin + step);
	if (max_left < max_right)
		return (true);
	return (false);
}

int	PmergeMe::get_max(std::vector<int> tabv, int idx, int end)
{
	int max = tabv[idx];
	while (idx < end)
	{
		if (idx + 1 == end)
			return (max);
		if (max < tabv[idx + 1])
			max = tabv[idx + 1];
		idx++;
	}
	return (max);
}

void	PmergeMe::ford_johnson_vec(std::vector<int> &vec, int pair)
{
	int		v_size = vec.size();

	// to stop recursive call when the pair size if bigger than the half of the container size
	if (v_size / pair	 < 1)
		return ;
	// Sort the pairs
	for (int begin = 0; begin < v_size; begin += pair)
	{
		if (begin + pair > v_size)
			break;
		if (!is_sorted(vec, begin, pair))
			swap(vec, begin, pair);
	}
	// Recursive call doubling the "pair" size
	ford_johnson_vec(vec, pair * 2);

	std::vector<int>	main;
	// Insert the two first pairs {b1, a1}
	main.insert(main.begin(), vec.begin(), vec.begin() + pair);

	std::vector<int>	pend;
	std::vector<int>	odd;
	std::vector<int>	temp; // What doesn't fit on the pair distribution
	int					main_nb = 0; 

	// Insert the rest of the pairs
	for (int i = pair; i < v_size; i += pair)
	{
		if (i + pair > v_size)
		{
			// Inserting odd
			if (i + pair / 2 - 1 < v_size)
				odd.insert(odd.begin(), vec.begin() + pair * (main_nb + 1), vec.begin() + pair * (main_nb + 1) + (pair / 2));
			// Inserting temp (elements that havent been paired)
			if (v_size % (pair / 2) != 0)
				temp.insert(temp.begin(), vec.end() - (v_size % (pair / 2)) , vec.end());
			break ;
		}
		// Inserting the main
		main.insert(main.begin() + main.size(), vec.begin() + pair * (main_nb + 1) + (pair / 2), vec.begin() + pair * (main_nb + 2));
		// Inserting the pend
		pend.insert(pend.begin() + pend.size(), vec.begin() + pair * (main_nb + 1), vec.begin() + pair * (main_nb + 1) + (pair / 2));
		main_nb++;
	}

	int 	j = 0;
	int 	main_pair = 0;
	int 	inserted_pend = 0;
	int		first_pend = 0;
	int		jacob_nb = 0;
	int 	a = 0;
	int 	b = 0;

	if (pend.size() != 0)
	{
		while (pend.size() != 0)
		{
			jacob_nb = jacobsthal(j++);
			first_pend = inserted_pend + 2;
			b = (((jacob_nb + 1) - (first_pend)) * (pair / 2)) - 1;
			if (static_cast<unsigned long>(b) > (pend.size() - 1))
			{
				// put the b to the last index of the pend
				b = pend.size() - 1;
				jacob_nb = first_pend + ((pend.size() / (pair / 2)));
			}
			main_pair = (b + 1) / (pair / 2);
			for (int i = 0; i < main_pair; i++)
			{
				a = (inserted_pend + jacob_nb) * (pair / 2) - 1;
				binary_insertion(main, a, pend, b, pair);
				b -= (pair / 2);
				jacob_nb--;
				inserted_pend++;
			}
		}
		if (odd.size() != 0)
			binary_insertion(main, (main.size() - 1), odd, odd.size() - 1, pair);
		vec.erase(vec.begin(), vec.end());
		vec.insert(vec.begin(), main.begin(), main.end());
		if (temp.size() != 0)
			vec.insert(vec.begin() + vec.size(), temp.begin(), temp.end());
	}
	else if (odd.size() != 0)
	{
		binary_insertion(main, (main.size() - 1), odd, odd.size() - 1, pair);
		vec.erase(vec.begin(), vec.end());
		vec.insert(vec.begin(), main.begin(), main.end());
		if (temp.size() != 0)
			vec.insert(vec.begin() + vec.size(), temp.begin(), temp.end());
	}
}

// Ford-Johnson Algorithm with deque container

void	PmergeMe::swap(std::deque<int> &tabd, int begin, int step)
{
	std::deque<int> temp;
	temp.insert(temp.begin(), tabd.begin() + begin, tabd.begin() + begin + (step / 2));
	
	for (int i = begin; i < begin + (step / 2); i++)
		tabd[i] = tabd[i + (step / 2)]; 
	for (int i = begin + (step / 2); i < begin + step; i++)
		tabd[i] = temp[i - (begin + (step / 2))];
}

void	PmergeMe::binary_insertion(std::deque<int> &tab, int tab_idx, std::deque<int> &nb, int idx_nb, int pair)
{
	while (tab_idx >= 0 && tab[tab_idx] > nb[idx_nb])
		tab_idx -= pair / 2;
	if (tab_idx < 0)
		tab.insert(tab.begin(), nb.begin() + idx_nb - (pair / 2) + 1, nb.begin() + idx_nb + 1);
	else
		tab.insert(tab.begin() + tab_idx + 1, nb.begin() + idx_nb - (pair / 2) + 1, nb.begin() + idx_nb + 1);
	nb.erase(nb.begin() + idx_nb - (pair / 2) + 1, nb.begin() + idx_nb + 1);
}

bool PmergeMe::is_sorted(std::deque<int> tabd, int begin, int step)
{
	int max_left = get_max(tabd, begin, begin + step / 2);
	int max_right = get_max(tabd, begin + (step / 2), begin + step);
	if (max_left < max_right)
		return (true);
	return (false);
}

int	PmergeMe::get_max(std::deque<int> tabd, int idx, int end)
{
	int max = tabd[idx];
	while (idx < end)
	{
		if (idx + 1 == end)
			return (max);
		if (max < tabd[idx + 1])
			max = tabd[idx + 1];
		idx++;
	}
	return (max);
}

void	PmergeMe::ford_johnson_deque(std::deque<int> &deque, int pair)
{
	int	d_size = deque.size();

	// to stop recursive call when the pair size if bigger than the half of the container size
	if (d_size / pair	 < 1)
		return ;
	// Sort the pairs
	for (int begin = 0; begin < d_size; begin += pair)
	{
		if (begin + pair > d_size)
			break;
		if (!is_sorted(deque, begin, pair))
			swap(deque, begin, pair);
	}
	// Recursive call doubling the "pair" size
	ford_johnson_deque(deque, pair * 2);

	std::deque<int>	main;
	// Insert the two first pairs {b1, a1}
	main.insert(main.begin(), deque.begin(), deque.begin() + pair);

	std::deque<int>	pend;
	std::deque<int>	odd;
	std::deque<int>	temp; // What doen't fit on the pair distribution
	int				main_nb = 0; 

	// Insert the rest of the pairs
	for (int i = pair; i < d_size; i += pair)
	{
		if (i + pair > d_size)
		{
			// Inserting odd
			if (i + pair / 2 - 1 < d_size)
				odd.insert(odd.begin(), deque.begin() + pair * (main_nb + 1), deque.begin() + pair * (main_nb + 1) + (pair / 2));
			// Inserting temp (elements that havent been paired)
			if (d_size % (pair / 2) != 0)
				temp.insert(temp.begin(), deque.end() - (d_size % (pair / 2)) , deque.end());
			break ;
		}
		// Inserting the main
		main.insert(main.begin() + main.size(), deque.begin() + pair * (main_nb + 1) + (pair / 2), deque.begin() + pair * (main_nb + 2));
		// Inserting the pend
		pend.insert(pend.begin() + pend.size(), deque.begin() + pair * (main_nb + 1), deque.begin() + pair * (main_nb + 1) + (pair / 2));
		main_nb++;
	}

	int 	j = 0;
	int 	main_pair = 0;
	int 	inserted_pend = 0;
	int		first_pend = 0;
	int		jacob_nb = 0;
	int 	a = 0;
	int 	b = 0;

	if (pend.size() != 0)
	{
		while (pend.size() != 0)
		{
			jacob_nb = jacobsthal(j++);
			first_pend = inserted_pend + 2;
			b = (((jacob_nb + 1) - (first_pend)) * (pair / 2)) - 1;
			if (static_cast<unsigned long>(b) > (pend.size() - 1))
			{
				// put the b to the last index of the pend
				b = pend.size() - 1;
				jacob_nb = first_pend + ((pend.size() / (pair / 2)));
			}
			main_pair = (b + 1) / (pair / 2);
			for (int i = 0; i < main_pair; i++)
			{
				a = (inserted_pend + jacob_nb) * (pair / 2) - 1;
				binary_insertion(main, a, pend, b, pair);
				b -= (pair / 2);
				jacob_nb--;
				inserted_pend++;
			}
		}
		if (odd.size() != 0)
			binary_insertion(main, (main.size() - 1), odd, odd.size() - 1, pair);
		deque.erase(deque.begin(), deque.end());
		deque.insert(deque.begin(), main.begin(), main.end());
		if (temp.size() != 0)
			deque.insert(deque.begin() + deque.size(), temp.begin(), temp.end());
	}
	else if (odd.size() != 0)
	{
		binary_insertion(main, (main.size() - 1), odd, odd.size() - 1, pair);
		deque.erase(deque.begin(), deque.end());
		deque.insert(deque.begin(), main.begin(), main.end());
		if (temp.size() != 0)
			deque.insert(deque.begin() + deque.size(), temp.begin(), temp.end());
	}
}
