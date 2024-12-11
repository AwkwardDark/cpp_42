#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(Dog const &src) : Animal("Dog")
{
	std::cout << "Dog copy constructor called" << std::endl;
	operator=(src);
}

Dog &Dog::operator=(Dog const &src)
{
	if (this != &src)
	{
		this->_type = src._type;
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof woof..." << "🐶" << std::endl;
}

std::string Dog::getIdea(int i)
{
	return (this->_brain->ideas[i]);
}

void Dog::setIdea(std::string _idea, int i)
{
	this->_brain->ideas[i] = _idea;
}
