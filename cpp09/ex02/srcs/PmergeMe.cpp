#include "PmergeMe.hpp"

// Canonical Orthodox Form

PmergeMe::PmergeMe(void)
{
	throw std::runtime_error("No arguments given!");
}

PmergeMe::PmergeMe(std::string* args, int size)
{
	// Parse and initialize the two containers
	for(int i = 0; i < size; i++)
		parse_push(args[i]);

	// Display vector container unsorted
	std::cout << "Before: ";
	for(std::vector<int>::iterator itv1 = vec.begin(); itv1 != vec.end(); itv1++)
		std::cout << *itv1 << " ";
	std::cout << std::endl;

	// Executes the sort algorithm for the vector and measures the time elapsed
	clock_t	start_v = clock();
	ford_johnson_vec(vec);
	clock_t	end_v = clock();
	double	diff_vec = static_cast<double>(end_v - start_v) / CLOCKS_PER_SEC * 1000000;

	// Display vector container sorted
	std::cout << "After:  ";
	for(std::vector<int>::iterator itv2 = vec.begin(); itv2 != vec.end(); itv2++)
		std::cout << *itv2 << " ";
	std::cout << std::endl;

	// Executes the sort algorithm for the list and measures the time elapsed
	clock_t	start_l = clock();
	ford_johnson_list(list);
	clock_t	end_l = clock();
	double	diff_list = static_cast<double>(end_l - start_l) / CLOCKS_PER_SEC * 1000000;

	// Display the time taken by the algorithm with the vector
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << diff_vec << " us" << std::endl;

	// Display the time taken by the algorithm with the list
	std::cout << "Time to process a range of " << list.size() << " elements with std::list :   " << diff_list << " us" << std::endl;

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
		this->list = src.list;
		this->vec = src.vec;
	}
	return (*this);
}

// Parsing

void	PmergeMe::parse_push(std::string input)
{
	std::stringstream	sinput;
	long				nb;

	if (!is_integer(input))
		throw std::runtime_error("Error: " + input + " is not aan integer");
	sinput << input;
	sinput >> nb;
	if (nb < 0)
		throw std::runtime_error("Error: " + input + " is a negative integer");
	if (nb > 2147483647)
		throw std::runtime_error("Error: " + input + " overflows int type capacity");
	vec.push_back(nb);
	list.push_back(nb);
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

// Ford-Johnson Algorithm

void	PmergeMe::ford_johnson_vec(std::vector<int> vec)
{
	(void)vec;
}

void	PmergeMe::ford_johnson_list(std::list<int> list)
{
	(void)list;
}
