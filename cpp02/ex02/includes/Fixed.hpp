/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:05:34 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/28 13:18:09 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

# define GREEN "\033[1;32m"
# define RESET "\033[0m"

class Fixed{
	
	private:
			int					value;
			static const int	frac_bits = 8;

	public:
			Fixed(void);
			Fixed(const int value);
			Fixed(const float value);
			Fixed(const Fixed &src);
			Fixed &operator=(const Fixed &src);
			~Fixed(void);
			int		getRawBits(void) const;
			void	setRawBits(int const raw);
			float	toFloat(void) const;
			int		toInt(void) const;
			
			//Comparison operators
			bool operator>(Fixed const &nbr) const;
			bool operator<(Fixed const &nbr) const;
			bool operator>=(Fixed const &nbr) const;
			bool operator<=(Fixed const &nbr) const;
			bool operator==(Fixed const &nbr) const;
			bool operator!=(Fixed const &nbr) const;

			//Arithmetic operators
			Fixed operator+(Fixed const &nbr) const;
			Fixed operator-(Fixed const &nbr) const;
			Fixed operator*(Fixed const &nbr) const;
			Fixed operator/(Fixed const &nbr) const;

			//Pre-increment operator
			Fixed operator++();

			//Post-increment operator
			Fixed operator++(int);

			//Pre-decrement operator
			Fixed operator--();

			//Post-decrement operator
			Fixed operator--(int);

			//Max and min constant functions
			static Fixed &min(Fixed &nbr1, Fixed &nbr2);
			static const Fixed &min(Fixed const &nbr1, Fixed const &nbr2);
			static Fixed &max(Fixed &nbr1, Fixed &nbr2);
			static const Fixed &max(Fixed const &nbr1, Fixed const &nbr2);

};

std::ostream &operator<<(std::ostream &out, Fixed const &src);

#endif
