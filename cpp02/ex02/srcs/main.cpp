/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:06:04 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/28 13:35:01 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c(Fixed(5) + Fixed(5));
	Fixed const d(Fixed(5.0f) + Fixed(5.0f) * Fixed(2));
	Fixed e(Fixed(5.0f) - Fixed(5.0f) / Fixed(2));

	std::cout << GREEN << "Testing arithmetic operators overload" << RESET << std::endl;
	std::cout << "c <==> 5 + 5:     " << c << std::endl;
	std::cout << "d <==> 5.0 + 5.0: " << d << std::endl;
	std::cout << "d <==> 5.0 - 5.0: " << e << std::endl;
	
	std::cout << GREEN << "Testing increment/decrement operators overload" << RESET << std::endl;
	std::cout << "--c: " << --c << std::endl;
	std::cout << "c:   " << c << std::endl;
	std::cout << "c--: " << c-- << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a:   " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a:   " << a << std::endl;
	std::cout << "b:   " << b << std::endl;
	
	std::cout << GREEN << "Testing max/min functions" << RESET << std::endl;
	std::cout << "max: " << Fixed::max(a, b) << std::endl;
	std::cout << "min: " << Fixed::min(a, b) << std::endl;

	std::cout << GREEN << "Additionals tests" << RESET << std::endl;
	
	Fixed f(10.2f);
	Fixed g(15.3f);

	std::cout << "f - g: " << f - g << std::endl;
	std::cout << "f + g: " << f + g << std::endl;
	std::cout << "f * g: " << f * g << std::endl;

	Fixed h(20.0f);
	Fixed i(0);
	Fixed j(3);

	std::cout << "h / i: " << h / i << std::endl;
	std::cout << "h * i: " << h * i << std::endl;
	std::cout << "j++:   " << j++ << std::endl;
	std::cout << "j:     " << j << std::endl;

	return (0);
}
