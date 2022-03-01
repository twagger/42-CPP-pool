/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/03/01 16:06:46 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	if (!SILENT)
		std::cout << ">> +👾 WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	if (!SILENT)
		std::cout << ">> +👾 WrongAnimal param constructor called" << std::endl;	
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	if (!SILENT)
		std::cout << ">> +👾 WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void)
{
	if (!SILENT)
		std::cout << ">> -👾 WrongAnimal destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Blip Blip" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

/*
** Operators overload
*/

// Assignment operator
WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &rhs)
{
	if (!SILENT)
		std::cout << ">> =🐾 WrongAnimal assignment operator called" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

// Insertion operator
std::ostream	&operator<<(std::ostream &o, WrongAnimal const &i)
{
	o << i.getType();
	return (o);
}