/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:48:40 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/28 13:38:06 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	float	Ax, Ay, Bx, By, Cx, Cy, pointx, pointy;

	std::cout <<"Input x coordinate for corner A of the triangle: ";
	std::cin >> Ax;
	std::cout << "Input y coordinate for corner A of the triangle: ";
	std::cin >> Ay;
	
	std::cout << "Input x coordinate for corner B of the triangle: ";
	std::cin >> Bx;
	std::cout << "Input y coordinate for corner B of the triangle: ";
	std::cin >> By;

	std::cout << "Input x coordinate for corner C of the triangle: ";
	std::cin >> Cx;
	std::cout << "Input y coordinate for corner C of the triangle: ";
	std::cin >> Cy;

	std::cout << "Input x coordinate for point P: ";
	std::cin >> pointx;
	std::cout << "Input y coordinate for point P: ";
	std::cin >> pointy;

	Point point(pointx, pointy);
	Point a(Ax, Ay);
	Point b(Bx, By);
	Point c(Cx, Cy);

	if (bsp(a, b, c, point))
		std::cout << GREEN << "The point is inside the triangle" << RESET << std::endl;
	else
		std::cout << RED << "The point is outside the triangle" << RESET << std::endl;

	return (0);
}
