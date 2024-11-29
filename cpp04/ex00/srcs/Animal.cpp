/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:41:38 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/29 19:48:22 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Undefined")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal const &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	operator=(src);
}

Animal &Animal::operator=(Animal const &src)
{
	this->_type = src._type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "Strange inaudible animal sound" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}
