/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:32:24 by twagner           #+#    #+#             */
/*   Updated: 2022/03/01 17:24:33 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Character.hpp" 
#include "AMateria.hpp"
#include "ICharacter.hpp"
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

Character::Character(void) : ICharacter(), _name("John Doe") 
{
	int	i;

	if (!SILENT)
		std::cout << ">> +🤴 Character default constructor called" << std::endl;
	i = -1;
	while (++i < INVENTORY_SIZE)
		this->_inventory[i] = NULL;
}

Character::Character(std::string const &name) : ICharacter(), _name(name)
{
	int	i;
	
	if (!SILENT)
		std::cout << ">> +🤴 Character param constructor called" << std::endl;
	i = -1;
	while (++i < INVENTORY_SIZE)
		this->_inventory[i] = NULL;
}

Character::Character(Character const &src)
{
	if (!SILENT)
		std::cout << ">> +🤴 Character copy constructor called" << std::endl;
	*this = src;
}

Character::~Character(void)
{
	if (!SILENT)
		std::cout << ">> -🤴 Character destructor called" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

/*
** Member functions and acessors
*/

std::string const	&Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	int i;

	i = 0;
	while (i < INVENTORY_SIZE && this->_inventory[i] != NULL)
		++i;
	if (i < INVENTORY_SIZE)
		this->_inventory[i] = m;
	else
	{
		std::cout << "<ERROR> Inventory is full, the materia has not been added." << std::endl;
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > INVENTORY_SIZE - 1)
	{
		std::cout << "<ERROR> Wrong inventory index, please provide a correct index" << std::endl;
		return ;
	}
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > INVENTORY_SIZE - 1)
	{
		std::cout << "<ERROR> Wrong inventory index, please provide a correct index" << std::endl;
		return ;
	}
	else if (this->_inventory[idx] == NULL)
	{
		std::cout << "<ERROR> Inventory index is empty, please provide an index containing a materia" << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}

/*
** Operators overload
*/

// Assignment operator
Character	&Character::operator=(Character const &rhs)
{
	if (!SILENT)
		std::cout << ">> =🤴 Character assignment operator called" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (rhs._inventory[i])
		{
			this->_inventory[i] = rhs._inventory[i]->clone();
		}
	}
	return (*this);
}
