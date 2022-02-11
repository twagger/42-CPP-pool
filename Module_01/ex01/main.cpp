/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:12:03 by twagner           #+#    #+#             */
/*   Updated: 2022/02/11 12:16:39 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int	main(void)
{
	int		i;
	int		nb;
	Zombie	*horde;

	nb = 4;
	std::cout << "-------------------------------" << std::endl;
	std::cout << "| Creating a horde of " << nb << " zombies |" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	horde = zombieHorde(nb, "bob");
	i = -1;
	while (++i < nb)
	{
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}
