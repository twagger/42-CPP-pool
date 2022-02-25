/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:01:23 by twagner           #+#    #+#             */
/*   Updated: 2022/02/25 11:17:03 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

Brain::Brain(void)
{
	if (!SILENT)
		std::cout << ">> +🧠 Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << ">> +🧠 Brain copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	if (!SILENT)
		std::cout << ">> +🧠 Brain destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

std::string	Animal::getType(void) const
{
	return (this->_type);
}

/*
** Operators overload
*/

// Assignment operator
Brain	&Brain::operator=(Brain const &rhs)
{
	if (!SILENT)
		std::cout << ">> =🧠 Brain assignment operator called" << std::endl;
	return (*this);
}
