/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/02/15 12:05:45 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

int	const Fixed::_nbBits = 8;

/*
** Constructor and destructor
*/

Fixed::Fixed(void)
{
	std::cout << ">> + Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(int value)
{
	std::cout << ">> + Int constructor called" << std::endl;
	this->_value = value * 256;
}

Fixed::Fixed(float value)
{
	std::cout << ">> + Float constructor called" << std::endl;
	this->_value = roundf(value * 256);
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << ">> + Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << ">> - Fixed destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw; 
}

float	Fixed::toFloat(void) const
{
	return ((float)this->getRawBits()/256);
}

int	Fixed::toInt(void) const
{
	return (int(this->getRawBits()/256));
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << ">> < Assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}
