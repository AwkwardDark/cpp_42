#include "Character.hpp"

Character::Character(void) : _name("Auguste")
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
	for (int i = 0; i < 4; i++)
	{
		if (this->slots[i])
			delete this->slots[i];
	}
	std::cout << "Character destructor called" << std::endl;
}

Character::Character(Character const &src) : _name(src.getName())
{
	for (int i = 0; i < 4; i++)
	{
		if (this->slots[i])
		{
			delete this->slots[i];
			if (src.slots[i])
				this->slots[i] = src.slots[i];
			else
				this->slots[i] = NULL;
		}
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character &Character::operator=(Character const &src)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->slots[i])
			delete this->slots[i];
	}
	for (int i = 0; i < 4; i++)
		this->slots[i] = src.slots[i]->clone();
	return (*this);
}

std::string const &Character::getName(void) const
{
	return (this->_name);
}

void Character::equip(AMateria *mat)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->slots[i])
		{
			this->slots[i] = mat;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "This inventory index doesnt't exist, you only have 4 slots" << std::endl;
		return;
	}
	if (!this->slots[idx])
	{
		std::cout << "There isn't an item at this index, impossible to unequip" << std::endl;
		return;
	}
	else if (this->slots[idx])
	{
		std::cout << "Unequiping materia at index: " << idx << std::endl;
		this->slots[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "This materia index doesnt't exit, you only have 4 slots" << std::endl;
		return;
	}
	if (!this->slots[idx])
	{
		std::cout << "There isn't an item at index: " << idx << std::endl;
		return;
	}
	this->slots[idx]->use(target);
}
