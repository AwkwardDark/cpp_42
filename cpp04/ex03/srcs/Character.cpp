#include "Character.hpp"

Character::Character(void)
{
	for (int i = 0; i < 4; i++)
		this->slots[i] = NULL;
	std::cout << "Character constructor called" << std::endl;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->slots[i] = NULL;
	std::cout << "Character constructor called" << std::endl;
}

Character::~Character(void)
{
	std::cout << "Character destructor called" << std::endl;
	delete[] this->slots;
}

Character::Character(Character const &src)
{
	std::cout << "Character copy constructor called" << std::endl;
	operator=(src);
}

Character &Character::operator=(Character const &src)
{
	return (*this);
}
