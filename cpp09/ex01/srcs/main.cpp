#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		std::cerr << std::endl << "Format: ./RPN <operations>" << std::endl;
	}
	else
	{
		try
		{
			RPN evaluate(argv[1]);
		}
		catch (const std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	return (0);
}
