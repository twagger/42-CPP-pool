/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/02/26 17:36:58 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

AAnimal::AAnimal(void) : _type("Animal")
{
	if (!SILENT)
		std::cout << ">> +🐾 AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	if (!SILENT)
		std::cout << ">> +🐾 AAnimal param constructor called" << std::endl;	
}

AAnimal::AAnimal(AAnimal const &src)
{
	std::cout << ">> +🐾 AAnimal copy constructor called" << std::endl;
	*this = src;
}

AAnimal::~AAnimal(void)
{
	if (!SILENT)
		std::cout << ">> -🐾 AAnimal destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

void	AAnimal::makeSound(void) const
{
	std::cout << "Greuuuuaaaaarrrrh !" << std::endl;
}

/*
** Operators overload
*/

// Assignment operator
AAnimal	&AAnimal::operator=(AAnimal const &rhs)
{
	if (!SILENT)
		std::cout << ">> =🐾 Animal assignment operator called" << std::endl;
	(void)rhs;
	return (*this);
}
