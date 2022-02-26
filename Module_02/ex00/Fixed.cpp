/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/02/26 09:31:42 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	const Fixed::_nbBits = 8;

/*
** Constructor and destructor
*/

Fixed::Fixed(void)
{
	std::cout << ">> + Fixed default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << ">> + Fixed copy constructor called" << std::endl;
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
	std::cout << ">> > getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << ">> < setRawBits member function called" << std::endl;
	this->_value = raw; 
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << ">> = Assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}
