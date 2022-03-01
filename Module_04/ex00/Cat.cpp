/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:26:16 by twagner           #+#    #+#             */
/*   Updated: 2022/03/01 09:13:01 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

Cat::Cat(void) : Animal("Cat")
{
	if (!SILENT)
		std::cout << ">> +🐈 Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &src) : Animal("Cat")
{
	std::cout << ">> +🐈 Cat copy constructor called" << std::endl;
	(void)src;
}

Cat::~Cat(void)
{
	if (!SILENT)
		std::cout << ">> -🐈 Cat destructor called" << std::endl;
}

/*
** Operators overload
*/

// Assignment operator
Cat	&Cat::operator=(Cat const &)
{
	if (!SILENT)
		std::cout << ">> =🐈 Cat assignment operator called" << std::endl;
	return (*this);
}

/*
** Member functions & accessors
*/

void	Cat::makeSound(void) const
{
	std::cout << "Miaouuuuu !" << std::endl;
}
