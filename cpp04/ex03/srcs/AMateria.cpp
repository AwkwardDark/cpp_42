#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(AMateria const &src)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	operator=(src);
}

AMateria &AMateria::operator=(AMateria const &src)
{
	return (*this);
}

std::string const &AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	if (this->_type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	if (this->_type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
