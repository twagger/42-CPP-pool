/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:12:03 by twagner           #+#    #+#             */
/*   Updated: 2022/02/11 11:27:51 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int	main(void)
{
	Zombie	*heap_zombie;

	std::cout << "-------------------------------" << std::endl;
	std::cout << "| New Zombie Creation (stack) |" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	randomChump("Jim");
	std::cout << "-------------------------------" << std::endl;
	std::cout << "| New Zombie Creation (heap)  |" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	heap_zombie = newZombie("Bob");
	heap_zombie->announce();
	delete heap_zombie;
	return (0);
}
