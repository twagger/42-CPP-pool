/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:02:15 by twagner           #+#    #+#             */
/*   Updated: 2022/02/18 16:17:58 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

static float	sign (Point point, Point p1, Point p2)
{
	return ((p2.getX().toFloat() - p1.getX().toFloat()) * (point.getY().toFloat() - p1.getY().toFloat()) \
		 - (p2.getY().toFloat() - p1.getY().toFloat()) * (point.getX().toFloat() - p1.getX().toFloat()));
}

/*
** The BSP function will check for each "side" of the triangle if it is on the left,
** right or on the side with the "sign" function (returning >0, <0 or 0)
** If the point is on the same "side" for each part of the triangle, it is inside.
*/

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	d1;
	float	d2;
	float	d3;
	bool	has_neg;
	bool	has_pos;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);
	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}
