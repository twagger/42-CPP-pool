/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/02/27 09:14:53 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

Ice::Ice(void) : AMateria("ice")
{
	if (!SILENT)
		std::cout << ">> +🧊 Ice default constructor called" << std::endl;
}

Ice::Ice(Ice const &src) : AMateria("ice")
{
	if (!SILENT)
		std::cout << ">> +🧊 Ice copy constructor called" << std::endl;
	*this = src;
}

Ice::~Ice(void)
{
	if (!SILENT)
		std::cout << ">> -🧊 Ice destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

Ice	*Ice::clone(void) const
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at "
			  << target.getName() << " *" << std::endl;
}

/*
** Operators overload
*/

// Assignment operator
Ice	&Ice::operator=(Ice const &)
{
	if (!SILENT)
		std::cout << ">> =🧊 Ice assignment operator called" << std::endl;
	return (*this);
}
