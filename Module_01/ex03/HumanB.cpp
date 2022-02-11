/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:00:47 by twagner           #+#    #+#             */
/*   Updated: 2022/02/11 13:18:47 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

/*
** Constructor and destructor
*/

HumanA::HumanA(std::string name, Weapon weapon) : _name(name), _weapon(weapon)
{
	std::cout << ">> + HumanA constructor called" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << ">> - HumanA destructor called" << std::endl;
}

/*
** Member functions and accessors
*/

void	HumanA::attack(void)
{
	std::cout << this->_name
			  << " attacks with their "
			  << this->_weapon.getType()
			  << std::endl;
}
