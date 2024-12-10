#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(Cure const &src) : AMateria("cure")
{
	std::cout << "Cure copy constructor called" << std::endl;
	operator=(src);
}

Cure &Cure::operator=(Cure const &src)
{
	return (*this);
}

AMateria *Cure::clone(void) const
{
	AMateria *clone = new Cure();
	return (clone);
}
