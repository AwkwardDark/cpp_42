/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:47:28 by pajimene          #+#    #+#             */
/*   Updated: 2024/11/28 13:24:38 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point{
	
	private:
			Fixed const x;
			Fixed const y;

	public:
			Point(void);
			Point(const float x, const float y);
			Point(const Point &point);
			Point &operator=(const Point &point);
			~Point(void);
			Fixed get_X(void) const;
			Fixed get_Y(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
