#include "iter.hpp"

// Function that increment the array element value and displays it
template <typename T>
void	increment(T &elem)
{
	elem++;
}

// Function that displays the array strings
void	display(std::string &str)
{
	std::cout << str << " ";
}

int	main(void)
{
	// Declare some array types
	int			int_tab[5] = {1, 6, -8, 345, 0};
	char		char_tab[5] = {'a', 'c', 'e', 'r', '4'};
	std::string	string_tab[5] = {"coucou", "comment", "tu", "vas", "?"};

	std::cout << "Int tab:    ";
	iter<int>(int_tab, 5, increment<int>);
	for(int i = 0; i < 5; i++)
		std::cout << int_tab[i] << " ";
	std::cout << std::endl << std::string(35, '*') << std::endl;
	
	std::cout << "Char tab:   ";
	iter<char>(char_tab, 5, increment<char>);
	for(int i = 0; i < 5; i++)
		std::cout << char_tab[i] << " ";
	std::cout << std::endl << std::string(35, '*') << std::endl;

	std::cout << "String tab: ";
	iter(string_tab, 5, display);
	std::cout << std::endl << std::string(35, '*') << std::endl;

	return (0);
}

