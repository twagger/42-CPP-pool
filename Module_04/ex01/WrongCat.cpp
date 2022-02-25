/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:26:16 by twagner           #+#    #+#             */
/*   Updated: 2022/02/25 17:05:24 by twagner          ###   ########.fr       */
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

WrongCat::WrongCat(void) : WrongAnimal()
{
	if (!SILENT)
		std::cout << ">> +🐄 WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	if (!SILENT)
		std::cout << ">> +🐄 WrongCat param constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src)
{
	std::cout << ">> +🐄 WrongCat copy constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void)
{
	if (!SILENT)
		std::cout << ">> -🐄 WrongCat destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

void	WrongCat::makeSound(void) const
{
	std::cout << "Meuuuh... ... Miaouu ?" << std::endl;
}