/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:26:16 by twagner           #+#    #+#             */
/*   Updated: 2022/03/01 15:50:21 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	if (!SILENT)
		std::cout << ">> +🐄 WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal("WrongCat")
{
	if (!SILENT)
		std::cout << ">> +🐄 WrongCat copy constructor called" << std::endl;
	(void)src;
}

WrongCat::~WrongCat(void)
{
	if (!SILENT)
		std::cout << ">> -🐄 WrongCat destructor called" << std::endl;
}

/*
** Operators overload
*/

// Assignment operator
WrongCat	&WrongCat::operator=(WrongCat const &)
{
	if (!SILENT)
		std::cout << ">> =🐄 WrongCat assignment operator called" << std::endl;
	return (*this);
}

/*
** Member functions & accessors
*/

void	WrongCat::makeSound(void) const
{
	std::cout << "Meuuuh... ... Miaouu ?" << std::endl;
}
