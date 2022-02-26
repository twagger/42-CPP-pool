/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:17:24 by twagner           #+#    #+#             */
/*   Updated: 2022/02/26 17:05:47 by twagner          ###   ########.fr       */
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
	this->_brain = new Brain();
}

Dog::Dog(Dog const &src) : Animal("Dog")
{
	std::cout << ">> +🐕 Dog copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this->_brain = *(src.getBrain());
}

Dog::~Dog(void)
{
	if (!SILENT)
		std::cout << ">> -🐕 Dog destructor called" << std::endl;
	delete this->_brain;
}

/*
** Member functions & accessors
*/

void	Dog::makeSound(void) const
{
	std::cout << "Ouaf !" << std::endl;
}

int	Dog::addIdea(const std::string idea)
{
	return (this->_brain->addIdea(idea));
}

int	Dog::removeIdea(int num)
{
	return (this->_brain->removeIdea(num));
}

void	Dog::displayIdeas(void) const
{
	this->_brain->displayIdeas();
}

Brain	*Dog::getBrain(void) const
{
	return (this->_brain);
}
