/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/02/27 09:14:53 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

Cure::Cure(void) : AMateria("cure")
{
	if (!SILENT)
		std::cout << ">> +💊 Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const &src) : AMateria("cure")
{
	if (!SILENT)
		std::cout << ">> +💊 Cure copy constructor called" << std::endl;
	*this = src;
}

Cure::~Cure(void)
{
	if (!SILENT)
		std::cout << ">> -💊 Cure destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

Cure	*Cure::clone(void) const
{
	return (new Cure());
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at "
			  << target.getName() << std::endl;
}

/*
** Operators overload
*/

// Assignment operator
Cure	&Cure::operator=(Cure const &)
{
	if (!SILENT)
		std::cout << ">> =💊 Cure assignment operator called" << std::endl;
	return (*this);
}
