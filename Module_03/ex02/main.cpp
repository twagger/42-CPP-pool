/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:12:03 by twagner           #+#    #+#             */
/*   Updated: 2022/02/19 12:46:47 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap	bob("Bob");
	ScavTrap	tom("Tom");
	FragTrap	jerry("Jerry");

	// Actions
	tom.attack("Jerry");
	if (tom.getEnergyPoint() && tom.getHitPoint())
		jerry.takeDamage(tom.getAttackDamage());
	tom.guardGate();
	jerry.attack("Tom");
	if (jerry.getEnergyPoint() && jerry.getHitPoint())
		tom.takeDamage(jerry.getAttackDamage());
	tom.attack("Jerry");
	if (tom.getEnergyPoint() && tom.getHitPoint())
		jerry.takeDamage(tom.getAttackDamage());
	jerry.highFivesGuys();

	// Status
	std::cout << jerry << " energy : " << jerry.getEnergyPoint()
			  << " - life : " << jerry.getHitPoint() << std::endl;
	std::cout << tom << " energy : " << tom.getEnergyPoint()
			  << " - life : " << tom.getHitPoint() << std::endl;
	std::cout << bob << " energy : " << bob.getEnergyPoint()
			  << " - life : " << bob.getHitPoint() << std::endl;

	return (0);
}