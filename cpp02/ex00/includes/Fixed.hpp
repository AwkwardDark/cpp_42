/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:06:08 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/27 15:22:58 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{
	
	private:
			int					value;
			static const int	frac_bits = 8;
		
	public:
			Fixed(void);
			Fixed(const Fixed &src);
			Fixed &operator=(const Fixed &src);
			~Fixed(void);
			int		getRawBits(void) const;
			void	setRawBits(int const raw);

};

#endif