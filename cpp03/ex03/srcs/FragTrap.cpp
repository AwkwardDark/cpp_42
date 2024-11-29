/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:29:56 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/29 16:35:00 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->health = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->_name = name;
	this->health = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	operator=(src);
}
//Operator = overload

FragTrap &FragTrap::operator=(FragTrap const &src)
{
	this->_name = src._name;
	this->health = src.health;
	this->energy = src.energy;
	this->damage = src.damage;
	return (*this);
}

//Methods

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " request a positive high fives :)" << std::endl;
}

