/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/02/12 17:17:53 by twagner          ###   ########.fr       */
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

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << ">> < Assignment operator called" << std::endl;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &i)
{
	o << i.
	return (o);
}
