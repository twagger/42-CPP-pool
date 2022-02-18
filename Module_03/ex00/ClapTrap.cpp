/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/02/18 17:37:17 by twagner          ###   ########.fr       */
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

ClapTrap::ClapTrap(void) : _name("John Doe"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	if (!SILENT)
		std::cout << ">> + ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
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

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target
				  << ", causing "
				  << this->_attackDamage << " points of damage !" << std::endl;
		this->_energyPoints -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	int	real_amount;

	if (amount > this->_hitPoints)
		real_amount = this->_hitPoints;
	else
		real_amount = amount;
	std::cout << "ClapTrap " << this->_name << " is attacked ! " 
			  << "He takes " << real_amount << " points of damage !" << std::endl;
	this->_hitPoints -= amount;

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " repares himself ! " 
			  	  << "He restores " << amount << " hit points !" << std::endl;
		this->_energyPoints -= 1;
	}
}

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

int	ClapTrap::getHitPoint(void) const
{
	return (this->_hitPoints);
}

int	ClapTrap::getEnergyPoint(void) const
{
	return (this->_energyPoints);
}

int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

/*
** Operators overload
*/

// Assignment operator
ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{
	if (!SILENT)
		std::cout << ">> < ClapTrap assignment operator called" << std::endl;
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoint();
	this->_energyPoints = rhs.getEnergyPoint();
	this->_attackDamage = rhs.getAttackDamage();
	return (*this);
}

// Insertion operator
std::ostream	&operator<<(std::ostream &o, ClapTrap const &i)
{
	o << i;
	return (o);
}