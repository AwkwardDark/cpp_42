/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:47:39 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/29 16:29:22 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->health = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->_name = name;
	this->health = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	operator=(src);
}
//Operator = overload

ScavTrap &ScavTrap::operator=(ScavTrap const &src)
{
	this->_name = src._name;
	this->health = src.health;
	this->energy = src.energy;
	this->damage = src.damage;
	return (*this);
}

//Methods

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " is now in Gate Keeper Mode" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->getEnergy() > 0 && this->getHealth() > 0)
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getDamage() << " point of damage!" << std::endl;
		this->energy--;
	}
	else if (this->getEnergy() == 0 && this->getHealth() > 0)
		std::cout << "ScavTrap " << this->getName() << " can't attack " << target << "because it doesn't have enough energy!" << std::endl;
	else if (this->getHealth() <= 0)
		std::cout << "ScavTrap " << this->getName() << " can't attack because it's dead" << std::endl;
}
