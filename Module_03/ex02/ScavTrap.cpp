/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:17:24 by twagner           #+#    #+#             */
/*   Updated: 2022/02/19 12:34:25 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

ScavTrap::ScavTrap(void)
{
	if (!SILENT)
		std::cout << ">> +🐕 ScavTrap default constructor called" << std::endl;
	this->_name = "John Doe";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) 
{
	if (!SILENT)
		std::cout << ">> +🐕 ScavTrap param constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::~ScavTrap(void)
{
	if (!SILENT)
		std::cout << ">> -🐕 ScavTrap destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "[🗡️ ] ScavTrap " << *this << " attacks " << target
				  << ", causing "
				  << this->_attackDamage << " points of damage !" << std::endl;
		this->_energyPoints -= 1;
	}
	else
		std::cout << "[🔋] ScavTrap " << *this << " cannot attack : not enought energy/ dead." << std::endl;
}

void	ScavTrap::guardGate(void) const
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
		std::cout << "[⛩️ ] ScavTrap " << *this << " entered Gate Keeper mode !" << std::endl;
	else
		std::cout << "[🔋] ScavTrap " << *this << " cannot switch mode : not enought energy/ dead." << std::endl;
}
