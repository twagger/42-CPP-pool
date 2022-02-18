/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/02/18 15:45:40 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

int	const Fixed::_nbBits = 8;

/*
** Constructor and destructor
*/

Fixed::Fixed(void)
{
	if (!SILENT)
		std::cout << ">> + Fixed default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(int value)
{
	if (!SILENT)
		std::cout << ">> + Fixed int constructor called" << std::endl;
	this->_value = value * 256;
}

Fixed::Fixed(float value)
{
	if (!SILENT)
		std::cout << ">> + Fixed float constructor called" << std::endl;
	this->_value = roundf(value * 256);
}

Fixed::Fixed(Fixed const &src)
{
	if (!SILENT)
		std::cout << ">> + Fixed copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	if (!SILENT)
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

Fixed	&Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 <= f2)
		return (f1);
	return (f2);
}

Fixed	Fixed::min(Fixed const &f1, Fixed const &f2)
{
	if (f1 <= f2)
		return (Fixed(f1));
	return (Fixed(f2));
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 >= f2)
		return (f1);
	return (f2);
}

Fixed	Fixed::max(Fixed const &f1, Fixed const &f2)
{
	if (f1 >= f2)
		return (Fixed(f1));
	return (Fixed(f2));
}

/*
** Operators overload
*/

// Assignment operator
Fixed	&Fixed::operator=(Fixed const &rhs)
{
	if (!SILENT)
		std::cout << ">> < Fixed assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

// Comparison operators
bool	Fixed::operator>(Fixed const &rhs) const
{
	if (this->_value > rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	if (this->_value < rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	if (this->_value >= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	if (this->_value <= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	if (this->_value == rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	if (this->_value != rhs.getRawBits())
		return (true);
	return (false);
}

// Arithmetic operators
Fixed	Fixed::operator+(Fixed const &rhs) const
{
	return (Fixed(this->_value + rhs.getRawBits()));
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	return (Fixed(this->_value - rhs.getRawBits()));
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	Fixed	tmpResult;
	int		res;
	
	res = ((int64_t)this->_value * (int64_t)rhs.getRawBits()) / (1 << 8);
	tmpResult.setRawBits(res);
	return (tmpResult);
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	Fixed	tmpResult;
	int		res;
	
	res = ((int64_t)this->_value * (1 << 8)) / rhs.getRawBits();
	tmpResult.setRawBits(res);
	return (tmpResult);
}	

// Increment / Decrement operators
Fixed	&Fixed::operator++(void)
{
	this->_value += 1;
	return (*this);
}

Fixed	Fixed::operator++(int value)
{
	Fixed tmp(*this);

	(void)value;
	this->_value += 1;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	this->_value -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int value)
{
	Fixed tmp(*this);

	(void)value;
	this->_value -= 1;
	return (tmp);
}

// Insertion operator
std::ostream	&operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}