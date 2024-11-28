/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:25:08 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/27 15:27:06 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed{
	
	private:
			int					value;
			static const int	frac_bits = 8;
		
	public:
			Fixed(void);
			Fixed(const int value);		
			Fixed(const float value);
			Fixed(const Fixed &fixed);
			Fixed &operator=(const Fixed &src);
			~Fixed(void);
			int		getRawBits(void) const;
			void	setRawBits(int const raw);
			float	toFloat(void) const;
			int		toInt(void) const;	
};

std::ostream &operator<<(std::ostream &out, Fixed const &src);

#endif