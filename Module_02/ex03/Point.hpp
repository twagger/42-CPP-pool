/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:09:21 by twagner           #+#    #+#             */
/*   Updated: 2022/02/18 13:42:16 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const &src);
		~Point();

		Point	&operator=(Point const &rhs);

		Fixed	getX(void) const;
		Fixed	getY(void) const;

	private:
		Fixed const	_x;
		Fixed const _y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);