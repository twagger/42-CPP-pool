/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:02:51 by twagner           #+#    #+#             */
/*   Updated: 2022/02/19 15:01:23 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap()
{
	if (!SILENT)
		std::cout << ">> +🧟 DiamondTrap default constructor called" << std::endl;
	this->_name = "John Doe";
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name)  
{
	if (!SILENT)
		std::cout << ">> +🧟 DiamondTrap param constructor called" << std::endl;
	this->_name = name;
	ClapTrap::_name = name.append("_clap_name");
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::~DiamondTrap(void)
{
	if (!SILENT)
		std::cout << ">> -🧟 DiamondTrap destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "🧟 I am both " << this->_name << " and " << this->ClapTrap::_name << std::endl;
}