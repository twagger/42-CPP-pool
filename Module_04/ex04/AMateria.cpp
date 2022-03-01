/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/03/01 16:15:34 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

AMateria::AMateria(void) : _type("materia")
{
	if (!SILENT)
		std::cout << ">> +🥙 AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type) 
{
	if (!SILENT)
		std::cout << ">> +🥙 AMateria param constructor called" << std::endl;	
}

AMateria::AMateria(AMateria const &src)
{
	if (!SILENT)
		std::cout << ">> +🥙 AMateria copy constructor called" << std::endl;
	*this = src;
}

AMateria::~AMateria(void)
{
	if (!SILENT)
		std::cout << ">> -🥙 AMateria destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &)
{
}

/*
** Operators overload
*/

// Assignment operator
AMateria	&AMateria::operator=(AMateria const &rhs)
{
	if (!SILENT)
		std::cout << ">> =🥙 AMateria assignment operator called" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}
