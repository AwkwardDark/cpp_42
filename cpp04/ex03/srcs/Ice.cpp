#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice constructor called" << std::endl;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(Ice const &src) : AMateria("ice")
{
	std::cout << "Ice copy constructor called" << std::endl;
	operator=(src);
}

Ice &Ice::operator=(Ice const &src)
{
	return (*this);
}

AMateria *Ice::clone(void) const
{
	AMateria *clone = new Ice();
	return (clone);
}
