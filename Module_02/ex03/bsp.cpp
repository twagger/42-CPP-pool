/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:02:15 by twagner           #+#    #+#             */
/*   Updated: 2022/02/26 09:48:23 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>


/*
** This function check on which plan (separated by p1 -> p2 line) is the point
** Returns >0 for one side, <0 for the other side, 0 if the point is on the line
*/

static float	sign (Point point, Point p1, Point p2)
{
	return ((p2.getX().toFloat() - p1.getX().toFloat()) * (point.getY().toFloat() - p1.getY().toFloat()) \
		 - (p2.getY().toFloat() - p1.getY().toFloat()) * (point.getX().toFloat() - p1.getX().toFloat()));
}

/*
** The BSP function will check for each "side" of the triangle if it is on the left,
** right or on the line with the "sign" function (returning >0, <0 or 0)
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
	std::cout << d1 << " " << d2 << " " << d3 << std::endl;
	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}
