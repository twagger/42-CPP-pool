/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:32:24 by twagner           #+#    #+#             */
/*   Updated: 2022/02/27 11:28:30 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Character.hpp" 
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
		std::cout << ">> +🧙🏻‍♂️ Character default constructor called" << std::endl;
	i = -1;
	while (++i < INVENTORY_SIZE)
		this->_inventory[i] = NULL;
}

Character::Character(std::string const &name) : ICharacter(), _name(name)
{
	int	i;
	
	if (!SILENT)
		std::cout << ">> +🧙🏻‍♂️ Character param constructor called" << std::endl;
	i = -1;
	while (++i < INVENTORY_SIZE)
		this->_inventory[i] = NULL;
}

Character::Character(Character const &src)
{
	if (!SILENT)
		std::cout << ">> +🧙🏻‍♂️ Character copy constructor called" << std::endl;
	*this = src;
}

Character::~Character(void)
{
	if (!SILENT)
		std::cout << ">> -🧙🏻‍♂️ Character destructor called" << std::endl;
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
		std::cout << "Inventory is full, the materia has not been added." << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > INVENTORY_SIZE - 1)
	{
		std::cout << "Wrong inventory index, please provide a correct index" << std::endl;
		return ;
	}
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > INVENTORY_SIZE - 1)
	{
		std::cout << "Wrong inventory index, please provide a correct index" << std::endl;
		return ;
	}
	else if (this->_inventory[idx] == NULL)
	{
		std::cout << "Inventory index is empty, please provide an index containing a materia" << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}

/*
** Operators overload
*/

// Assignment operator
Character	&Character::operator=(Character const &)
{
	if (!SILENT)
		std::cout << ">> =🧙🏻‍♂️ Character assignment operator called" << std::endl;
	return (*this);
}
