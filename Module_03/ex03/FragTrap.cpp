/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:38:09 by twagner           #+#    #+#             */
/*   Updated: 2022/02/26 11:47:11 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

FragTrap::FragTrap(void) : ClapTrap()
{
	if (!SILENT)
		std::cout << ">> +🐸 FragTrap default constructor called" << std::endl;
	this->_name = "John Doe";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	if (!SILENT)
		std::cout << ">> +🐸 FragTrap param constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap()
{
	std::cout << ">> +🐸 FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void)
{
	if (!SILENT)
		std::cout << ">> -🐸 FragTrap destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

void	FragTrap::highFivesGuys(void) const
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
		std::cout << "[✋] FragTrap " << *this << " proposed a high five !" << std::endl;
	else
		std::cout << "[🔋] FragTrap " << *this << " cannot propose high five : not enought energy/ dead." << std::endl;
}
