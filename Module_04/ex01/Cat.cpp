/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:26:16 by twagner           #+#    #+#             */
/*   Updated: 2022/03/01 16:03:17 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"
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
	this->_brain = new Brain();
}

Cat::Cat(Cat const &src) : Animal("Cat")
{
	if (!SILENT)
		std::cout << ">> +🐈 Cat copy constructor called" << std::endl;
	this->_brain = NULL;
	*this = src;
}

Cat::~Cat(void)
{
	if (!SILENT)
		std::cout << ">> -🐈 Cat destructor called" << std::endl;
	delete this->_brain;
}

/*
** Operators overload
*/

// Assignment operator
Cat	&Cat::operator=(Cat const &rhs)
{
	if (!SILENT)
		std::cout << ">> =🐈 Cat assignment operator called" << std::endl;
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain(*(rhs.getBrain()));
	return (*this);
}

/*
** Member functions & accessors
*/

void	Cat::makeSound(void) const
{
	std::cout << "Miaouuuuu !" << std::endl;
}

int	Cat::addIdea(const std::string idea)
{
	return (this->_brain->addIdea(idea));
}

int	Cat::removeIdea(int num)
{
	return (this->_brain->removeIdea(num));
}

void	Cat::displayIdeas(void) const
{
	this->_brain->displayIdeas();
}

Brain	*Cat::getBrain(void) const
{
	return (this->_brain);
}
