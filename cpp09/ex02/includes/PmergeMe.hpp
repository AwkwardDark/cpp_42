#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <exception>
# include <ctime>
# include <sstream>
# include <stdbool.h>

# define RED     "\033[31m"
# define RESET   "\033[0m"

class PmergeMe
{
	private:
		std::vector<int>	vec;
		std::list<int>		list;

	public:
		// COF
		PmergeMe(void);
		PmergeMe(std::string* args, int size);
		~PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		PmergeMe &operator=(PmergeMe const &src);

		// Parsing & sort algorithm methods
		void	parse_push(std::string input);
		void	ford_johnson_vec(std::vector<int> vec);
		void	ford_johnson_list(std::list<int> list);
		bool	is_integer(std::string str);
};

#endif
