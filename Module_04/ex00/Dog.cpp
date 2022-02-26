/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:17:24 by twagner           #+#    #+#             */
/*   Updated: 2022/02/26 17:06:23 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

Dog::Dog(void) : Animal("Dog")
{
	if (!SILENT)
		std::cout << ">> +🐕 Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &src) : Animal("Dog")
{
	std::cout << ">> +🐕 Dog copy constructor called" << std::endl;
	(void)src;
}

Dog::~Dog(void)
{
	if (!SILENT)
		std::cout << ">> -🐕 Dog destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

void	Dog::makeSound(void) const
{
	std::cout << "Ouaf !" << std::endl;
}
