#include "Brain.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "I want to eat!";
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	operator=(src);
}

Brain	&Brain::operator=(Brain const &src)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
