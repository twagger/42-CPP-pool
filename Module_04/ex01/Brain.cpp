/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:56:52 by twagner           #+#    #+#             */
/*   Updated: 2022/02/26 16:59:05 by twagner          ###   ########.fr       */
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
		std::cout << ">> -🧠 Brain destructor called" << std::endl;
}

/*
** Operators overload
*/

// Assignment operator
Brain	&Brain::operator=(Brain const &rhs)
{
	int	i;

	if (!SILENT)
		std::cout << ">> =🧠 Brain assignment operator called" << std::endl;
	i = -1;
	while (++i < 100)
	{
		if (!rhs._ideas[i].empty())
			this->_ideas[i]	= rhs._ideas[i];
	}
	return (*this);
}

/*
** Member functions
*/

int	Brain::addIdea(const std::string idea)
{
	int	i;

	i = 0;
	while (i < 100 && !this->_ideas[i].empty())
		++i;
	if (i < 100)
	{
		this->_ideas[i] = idea;
		return (i);
	}
	return (-1);	
}

int Brain::removeIdea(int num)
{
	if (num > 0 && num < 100)
	{
		if (!this->_ideas[num].empty())
			this->_ideas[num].clear();
		return (0);
	}
	return (1);
}


void	Brain::displayIdeas(void) const
{
	int i;

	i = -1;
	while (++i < 100)
	{
		if (!this->_ideas[i].empty())
			std::cout << "-Idea [" << i << "] is " << this->_ideas[i] << std::endl;
	}
}
