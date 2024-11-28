/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:48:24 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/28 12:33:22 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default constructor and setter
Fixed::Fixed(void)
{
	this->value = 0;
	//std::cout << "Default constructor called" << std::endl;
}

//Default destructor
Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

//"Int constructor"
Fixed::Fixed(const int value)
{
	//std::cout << "Int constructor called" << std::endl;
	this->value = (int)(value << this->frac_bits);
}

//"Float constructor"
Fixed::Fixed(const float value)
{
	//std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << this->frac_bits));
}

// Copy constructor
Fixed::Fixed(const Fixed &src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// operator = overload  
Fixed &Fixed::operator=(const Fixed &src)
{
	//std::cout << "Copy assignement operator called" << std::endl;
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

//Insertion << overload
std::ostream &operator<<(std::ostream &out, Fixed const &src)
{
	out << src.toFloat();
	return (out);
}

//Comparaisons overloads

bool	Fixed::operator>(Fixed const &nbr) const
{
	return (this->value > nbr.value);
}

bool	Fixed::operator<(Fixed const &nbr) const
{
	return (this->value < nbr.value);
}

bool	Fixed::operator==(Fixed const &nbr) const
{
	return (this->value == nbr.value);
}

bool	Fixed::operator!=(Fixed const &nbr) const
{
	return (this->value != nbr.value);
}

bool	Fixed::operator>=(Fixed const &nbr) const
{
	return (operator>(nbr) || operator==(nbr));
}

bool	Fixed::operator<=(Fixed const &nbr) const
{
	return (operator<(nbr) || operator==(nbr));
}

//Arithmetic operations overloads

Fixed	Fixed::operator+(Fixed const &nbr) const
{
	Fixed new_nbr;

	new_nbr.setRawBits(this->value + nbr.value);
	return (new_nbr);
}

Fixed	Fixed::operator-(Fixed const &nbr) const
{
	Fixed new_nbr;

	new_nbr.setRawBits(this->value - nbr.value);
	return (new_nbr);
}

Fixed	Fixed::operator*(Fixed const &nbr) const
{
	Fixed new_nbr;

	new_nbr.setRawBits(this->value * nbr.value >> frac_bits);
	return (new_nbr);
}

Fixed	Fixed::operator/(Fixed const &nbr) const
{
	Fixed new_nbr;

	if (nbr.getRawBits() == 0)
	{
		std::cout << "Division by 0 is forbidden" << std::endl;
		return (0);
	}
	new_nbr.setRawBits(this->value * (1 << frac_bits) / nbr.value);
	return (new_nbr);
}

//Pre-increment operator overload
Fixed	Fixed::operator++()
{
	++this->value;
	return (*this);
}

//Post-increment operator overload
Fixed	Fixed::operator++(int)
{
	Fixed	res;
	res.value = this->value++;
	return (res);
}

//Pre-decrement operator overload
Fixed	Fixed::operator--()
{
	--this->value;
	return (*this);
}

//Post-decrement operator overload
Fixed	Fixed::operator--(int)
{
	Fixed	res;
	res.value = this->value--;
	return (res);
}

//Max and min functions

Fixed &Fixed::min(Fixed &nbr1, Fixed &nbr2)
{
	if (nbr1 < nbr2)
		return (nbr1);
	return (nbr2);
}

Fixed &Fixed::max(Fixed &nbr1, Fixed &nbr2)
{
	if (nbr1 > nbr2)
		return (nbr1);
	return (nbr2);
}

//Const max and min functions

const Fixed &Fixed::min(Fixed const &nbr1, Fixed const &nbr2)
{
	if (nbr1 < nbr2)
		return (nbr1);
	return (nbr2);
}

const Fixed &Fixed::max(Fixed const &nbr1, Fixed const &nbr2)
{
	if (nbr1 > nbr2)
		return (nbr1);
	return (nbr2);
}
