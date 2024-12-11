#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog const &src) : Animal("Dog")
{
	std::cout << "Dog copy constructor called" << std::endl;
	operator=(src);
}

Dog &Dog::operator=(Dog const &src)
{
	this->_type = src._type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof woof..." << "🐶" << std::endl;
}
