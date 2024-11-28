/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:48:42 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/27 18:16:52 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(Fixed()), y(Fixed())
{
}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y))
{
}

Point::Point(const Point &point) : x(point.x), y(point.y)
{
}

Point::~Point(void)
{
}

Point &Point::operator=(const Point &point)
{
	(void)point;
	return (*this);
}

Fixed Point::get_X(void) const
{
	return (this->x);
}

Fixed Point::get_Y(void) const
{
	return (this->y);
}
