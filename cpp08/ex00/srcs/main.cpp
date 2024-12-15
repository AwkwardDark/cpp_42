#include "easyfind.hpp"

int main(void)
{
	std::list<int> lst;

	// Creating the ascending list
	for (int i = 0; i < 20; i++)
		lst.push_back(i);

	// Testing if easyfind creates the good iterator
	std::list<int>::iterator	it = easyfind(lst, 7);
	for(; it != lst.end(); it++)
		std::cout << *it << "  ";

	std::cout << std::endl << std::endl;

	// Trying to search and element that's not on the list
	std::cout << "Searching a non-existing element:" << std::endl;
	try
	{
		std::list<int>::iterator	it = easyfind(lst, 20);
		(void)it;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	// Doing the same tests with another type of container (vector)
	std::vector<int> vec;

	// Creating the ascending list
	for (int i = 0; i < 20; i++)
		vec.push_back(i);

	// Testing if easyfind creates the good iterator
	std::vector<int>::iterator	itv = easyfind(vec, 15);
	for(; itv != vec.end(); itv++)
		std::cout << *itv << "  ";

	std::cout << std::endl << std::endl;

	// Trying to search and element that's not on the list
	std::cout << "Searching a non-existing element:" << std::endl;
	try
	{
		std::vector<int>::iterator	itv = easyfind(vec, 20);
		(void)itv;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
