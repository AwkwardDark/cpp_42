#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(Cat const &src) : Animal("Cat")
{
	std::cout << "Cat copy constructor called" << std::endl;
	operator=(src);
}

Cat &Cat::operator=(Cat const &src)
{
	if (this != &src)
	{
		this->_type = src._type;
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

void Cat::makeSound(void) const
{
	std::cout << "Miaoouuuu..." << "🐱" << std::endl;
}

std::string Cat::getIdea(int i)
{
	return (this->_brain->ideas[i]);
}

void Cat::setIdea(std::string _idea, int i)
{
	this->_brain->ideas[i] = _idea;
}
