#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat const &src) : Animal("Cat")
{
	std::cout << "Cat copy constructor called" << std::endl;
	operator=(src);
}

Cat &Cat::operator=(Cat const &src)
{
	this->_type = src._type;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaoouuuu..." << "🐱" << std::endl;
}
