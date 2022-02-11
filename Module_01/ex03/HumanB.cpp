/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:00:47 by twagner           #+#    #+#             */
/*   Updated: 2022/02/11 15:07:10 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/*
** Constructor and destructor
*/

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = NULL;
	std::cout << ">> + HumanB constructor called" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << ">> - HumanB destructor called" << std::endl;
}

/*
** Member functions and accessors
*/

void	HumanB::attack(void) const
{
	if (this->_weapon)
	{
		std::cout << this->_name
				  << " attacks with their "
				  << this->_weapon->getType()
				  << std::endl;
	}
	else
		std::cout << this->_name
				  << " attacks with his hands"
				  << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
