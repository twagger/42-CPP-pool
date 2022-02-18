/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/02/18 16:51:06 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "ClapTrap.hpp"
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

ClapTrap::ClapTrap(void)
{
	if (!SILENT)
		std::cout << ">> + ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(int value)
{
	if (!SILENT)
		std::cout << ">> + ClapTrap param constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	if (!SILENT)
		std::cout << ">> - ClapTrap destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

/*
** Operators overload
*/

// Assignment operator
ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{
	if (!SILENT)
		std::cout << ">> < ClapTrap assignment operator called" << std::endl;
	return (*this);
}

// Insertion operator
std::ostream	&operator<<(std::ostream &o, ClapTrap const &i)
{
	o << i;
	return (o);
}