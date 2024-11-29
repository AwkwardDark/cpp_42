/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:47:50 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/28 18:10:23 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : health(10) , energy(10) , damage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name) , health(10) , energy(10) , damage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	operator=(src);
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	this->_name = src._name;
	this->damage = src.damage;
	this->energy = src.energy;
	this->health = src.health;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->energy > 0 && this->health > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->damage << " point of damage!" << std::endl;
		this->energy--;
	}
	else if (this->energy == 0 && this->health > 0)
		std::cout << "ClapTrap " << this->_name << " can't attack " << target << "because it doesn't have enough energy!" << std::endl;
	else if (this->health <= 0)
		std::cout << "ClapTrap " << this->_name << " can't attack because it's dead" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->health > 0)
	{
		std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage!" << std::endl;
		this->health -= amount;
	}
	else
		std::cout << "ClapTrap " << this->_name << " can't take more damage because it's dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy > 0 && this->health > 0)
	{
		std::cout << "ClapTrap " << this->_name << " took " << amount << " points of health!" << std::endl;
		this->health += amount;
		this->energy--;
	}
	else if (this->energy == 0 && this->health > 0)
		std::cout << "ClapTrap " << this->_name << " can't repair itself because it doesn't have enough energy!" << std::endl;
	else if (this->health <= 0)
		std::cout << "ClapTrap " << this->_name << " can't repair itself because it's dead" << std::endl;
}

//Getters

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

int	ClapTrap::getHealth(void) const
{
	return (this->health);
}

int	ClapTrap::getEnergy(void) const
{
	return (this->energy);
}

int	ClapTrap::getDamage(void) const
{
	return (this->damage);
}
