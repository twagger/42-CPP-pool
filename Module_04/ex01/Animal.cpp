/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/02/26 12:18:17 by twagner          ###   ########.fr       */
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

Animal::Animal(void) : _type("Animal")
{
	if (!SILENT)
		std::cout << ">> +🐾 Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	if (!SILENT)
		std::cout << ">> +🐾 Animal param constructor called" << std::endl;	
}

Animal::Animal(Animal const &src)
{
	std::cout << ">> +🐾 Animal copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal(void)
{
	if (!SILENT)
		std::cout << ">> -🐾 Animal destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

void	Animal::makeSound(void) const
{
	std::cout << "Greuuuuaaaaarrrrh !" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

/*
** Operators overload
*/

// Assignment operator
Animal	&Animal::operator=(Animal const &rhs)
{
	if (!SILENT)
		std::cout << ">> =🐾 Animal assignment operator called" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

// Insertion operator
std::ostream	&operator<<(std::ostream &o, Animal const &i)
{
	o << i.getType();
	return (o);
}
