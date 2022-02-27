/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 11:01:59 by twagner           #+#    #+#             */
/*   Updated: 2022/02/27 11:29:59 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

MateriaSource::MateriaSource(void) : IMateriaSource()
{
	int	i;

	if (!SILENT)
		std::cout << ">> +🌱 MateriaSource default constructor called" << std::endl;
	i = -1;
	while (++i < STOCK_SIZE)
		this->_stock[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src) : IMateriaSource()
{
	if (!SILENT)
		std::cout << ">> +🌱 MateriaSource copy constructor called" << std::endl;
	*this = src;
}

MateriaSource::~MateriaSource(void)
{
	if (!SILENT)
		std::cout << ">> -🌱 MateriaSource destructor called" << std::endl;
}


/*
** Member functions and acessors
*/

void	MateriaSource::learnMateria(AMateria *m)
{
	int i;

	i = 0;
	while (i < STOCK_SIZE && this->_stock[i] != NULL)
		++i;
	if (i < STOCK_SIZE)
		this->_stock[i] = m;
	else
		std::cout << "Stock is full, the materia has not been saved." << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	int i;

	i = 0;
	while (i < STOCK_SIZE && this->_stock[i] != NULL)
	{
		if (this->_stock[i]->getType().compare(type) == 0)
		{
			return (this->_stock[i]->clone());
		}
		++i;
	}
	std::cout << "No materia found with the name " << type << "in the materia source" << std::endl;
	return (NULL);
}

/*
** Operators overload
*/

// Assignment operator
MateriaSource	&MateriaSource::operator=(MateriaSource const &)
{
	if (!SILENT)
		std::cout << ">> =🌱 MateriaSource assignment operator called" << std::endl;
	return (*this);
}
