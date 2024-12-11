#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	operator=(src);
}

WrongCat &WrongCat::operator=(WrongCat const &src)
{
	this->_type = src._type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongMiaou..." << "🐱" << std::endl;
}
