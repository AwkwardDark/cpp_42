/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:37:10 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/28 13:09:23 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default constructor and setter
Fixed::Fixed(void)
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

//Default destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

//"Int constructor"
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = (int)(value << this->frac_bits);
}

//"Float constructor"
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << this->frac_bits));
}

// Copy constructor
Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// operator = overload  
Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &src)
		this->value = src.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	float res;

	res = (float)this->value / (1 << this->frac_bits);
	return (res);
}

int	Fixed::toInt(void) const
{
	int res;
	
	res = this->value >> this->frac_bits;
	return (res);
}

//Insertion operator overload
std::ostream &operator<<(std::ostream &out, Fixed const &src)
{
	out << src.toFloat();
	return (out);
}
