/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randumChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:12:54 by twagner           #+#    #+#             */
/*   Updated: 2022/02/11 11:17:21 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void	randomChump(std::string name)
{
	Zombie	my_zombie(name);

	my_zombie.announce();
}
