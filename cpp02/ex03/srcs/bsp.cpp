/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:49:23 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/28 12:39:53 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	area(Point const a, Point const b, Point const c, bool flag)
{
	Fixed	t1, t2, t3, total;
	float	area;

	t1 = a.get_X() * (b.get_Y() - c.get_Y());
	t2 = b.get_X() * (c.get_Y() - a.get_Y());
	t3 = c.get_X() * (a.get_Y() - b.get_Y());
	total = (t1 + t2 + t3) / 2;
	area = total.toFloat();
	if (area < 0)
		area *= -1;
	if (area == 0)
	{
		if (flag)
			std::cout << RED << "The point is on the triangle side, and not inside the triangle" << RESET << std::endl;
		return (-1);
	}
	return (area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	total_area, t1, t2, t3;

	total_area = area(a, b, c, false);
	if (total_area < 0)
	{
		std::cout << RED << "The 3 points doesn't make a triangle" << RESET << std::endl;
		return (0);
	}
	t1 = area(a, b, point, true);
	if (t1 < 0)
		return (0);
	t2 = area(a, c, point, true);
	if (t2 < 0)
		return (0);
	t3 = area(b, c, point, true);
	if (t3 < 0)
		return (0);
	return (total_area >= t1 + t2 + t3);
}
