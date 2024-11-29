/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:44:56 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/29 18:12:20 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("_clap_name") , _name("")
{
    this->health = FragTrap::health;
    this->energy = ScavTrap::getEnergyPoint();
    this->damage = FragTrap::damage;
    std::cout << "DiamondTrap Constructor called by " << _name << std::endl;
}


DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &obj)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
	operator=(obj);
}


DiamondTrap::DiamondTrap(std::string _name) : ClapTrap(_name + "_clap_name") , _name(_name)
{
    this->health = FragTrap::health;
    this->energy = ScavTrap::getEnergyPoint();
    this->damage = FragTrap::damage;
    std::cout << "DiamondTrap Constructor called by " << _name << std::endl;
}

void DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "_name: " << this->_name << ", ClapTrap _name: " << this->ClapTrap::_name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &src)
{
    this->energy = src.energy;
    this->damage = src.damage;
    this->health = src.health;
    this->_name = src._name;
    return (*this);
}
