/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:26:16 by twagner           #+#    #+#             */
/*   Updated: 2022/02/19 15:48:26 by twagner          ###   ########.fr       */
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

Cat::Cat(void) : Animal()
{
	if (!SILENT)
		std::cout << ">> +🐈 Cat default constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	if (!SILENT)
		std::cout << ">> +🐈 Cat param constructor called" << std::endl;
}

Cat::~Cat(void)
{
	if (!SILENT)
		std::cout << ">> -🐈 Cat destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

void	Cat::makeSound(void) const
{
	std::cout << "Miaouuuuu !" << std::endl;
}
