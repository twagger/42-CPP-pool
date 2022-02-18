/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:45:00 by twagner           #+#    #+#             */
/*   Updated: 2022/02/18 16:04:34 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructors and destructor
*/

Point::Point(void)
{
	if (!SILENT)
		std::cout << ">> + Point default constructor called" << std::endl;
}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y))
{
	if (!SILENT)
		std::cout << ">> + Point param constructor called" << std::endl;
}

Point::Point(Point const &src)
{
	if (!SILENT)
		std::cout << ">> + Point copy constructor called" << std::endl;
	*this = src;
}

Point::~Point()
{
	if (!SILENT)
		std::cout << ">> - Point destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}

/*
** Operators overload
*/

// Assignment operator
Point	&Point::operator=(Point const &rhs)
{
	if (!SILENT)
		std::cout << ">> < Point assignment operator called" << std::endl;
	*const_cast<Fixed*> (&_x)= rhs.getX();
	*const_cast<Fixed*> (&_y)= rhs.getY();
	return (*this);
}

