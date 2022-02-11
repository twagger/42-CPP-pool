/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/02/11 13:45:00 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/*
** Constructor and destructor
*/

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << ">> + Weapon constructor called" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << ">> - Weapon destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

std::string	const	&Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
