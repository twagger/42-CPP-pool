/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/02/25 16:55:18 by twagner          ###   ########.fr       */
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
		std::cout << ">> +🐰 ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	if (!SILENT)
		std::cout << ">> +🐰 ClapTrap param constructor called" << std::endl;	
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << ">> +🐰 ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	if (!SILENT)
		std::cout << ">> -🐰 ClapTrap destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "[🗡️ ] ClapTrap " << this->_name << " attacks " << target
				  << ", causing "
				  << this->_attackDamage << " points of damage !" << std::endl;
		this->_energyPoints -= 1;
	}
	else
		std::cout << "[🔋] ClapTrap " << *this << " cannot attack : not enought energy/ dead." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "[🛡️ ] ClapTrap " << this->_name << " is attacked ! " 
			  << "He takes " << amount << " points of damage !" << std::endl;
	if (amount > this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "[🔧] ClapTrap " << this->_name << " repares himself ! " 
			  	  << "He restores " << amount << " hit points !" << std::endl;
		this->_energyPoints -= 1;
		this->_hitPoints += amount;
	}
	else
		std::cout << "[🔋] ClapTrap " << *this << " cannot be repared : not enought energy/ dead." << std::endl;
}

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoint(void) const
{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoint(void) const
{
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
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
		std::cout << ">> =🐰 ClapTrap assignment operator called" << std::endl;
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoint();
	this->_energyPoints = rhs.getEnergyPoint();
	this->_attackDamage = rhs.getAttackDamage();
	return (*this);
}

// Insertion operator
std::ostream	&operator<<(std::ostream &o, ClapTrap const &i)
{
	o << i.getName();
	return (o);
}