/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:00:40 by twagner           #+#    #+#             */
/*   Updated: 2022/02/11 12:12:30 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	int		i;
	Zombie	*horde = new Zombie[N];

	i = -1;
	while (++i < N)
		horde[i].setName(name);
	return (horde);	
}