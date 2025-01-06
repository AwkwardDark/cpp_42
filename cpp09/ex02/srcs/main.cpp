#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Wrong input" << std::endl;
		std::cerr << std::endl << "Format: ./PmergeMe <int1> <int2> <...>" << std::endl;
	}
	else
	{
		std::string	args[argc - 1];
		for (int i = 0; i < argc - 1; i++)
			args[i] = argv[i + 1];
		try
		{
			PmergeMe sort(args, argc - 1);
		}
		catch (const std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	return (0);
}

//./PmergeMe $(shuf -i 1-10000 -n 3000 | tr "\n" " ") to test with 3000 random integers between 1 and 10000