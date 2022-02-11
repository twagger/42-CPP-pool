/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/02/11 12:17:38 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
** Constructor and destructor
*/

Zombie::Zombie(void)
{
	std::cout << ">> + Zombie constructor called" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << ">> - Zombie destructor called" << std::endl;
	std::cout << ">> < Zombie [" << this->_name << "] is dead, again" << std::endl;
}

/*
** Member functions & accessors
*/

void	Zombie::announce(void)
{
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}
