#include "easyfind.hpp"

int main(void)
{
	std::list<int> lst;

	lst.push_front(8);
	lst.push_front(2);
	lst.push_front(5);
	lst.push_front(2);
	lst.push_front(1);

	try
	{
		std::cout << "First ocurrence value: " << easyfind(lst, 5) << std::endl;
		std::cout << easyfind(lst, 7) << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::vector<int>	vect;

	vect.push_back(0);
	vect.push_back(4);
	vect.push_back(-9);
	vect.push_back(1);

	try
	{
		std::cout << std::endl << "First ocurrence value: " << easyfind(vect, 4) << std::endl;
		std::cout << easyfind(vect, 9) << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
