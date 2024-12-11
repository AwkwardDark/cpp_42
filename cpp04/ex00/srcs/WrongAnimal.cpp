#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Undefined")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	operator=(src);
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src)
{
	this->_type = src._type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Strange inaudible WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}
