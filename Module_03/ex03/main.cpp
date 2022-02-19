/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:12:03 by twagner           #+#    #+#             */
/*   Updated: 2022/02/19 14:38:05 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	ClapTrap	bob("Bob");
	ScavTrap	tom("Tom");
	FragTrap	jerry("Jerry");
	DiamondTrap	eric("Eric");	

	// Actions
	tom.attack("Jerry");
	if (tom.getEnergyPoint() && tom.getHitPoint())
		jerry.takeDamage(tom.getAttackDamage());
	tom.guardGate();
	jerry.attack("Tom");
	if (jerry.getEnergyPoint() && jerry.getHitPoint())
		tom.takeDamage(jerry.getAttackDamage());
	tom.attack("Eric");
	if (tom.getEnergyPoint() && tom.getHitPoint())
		eric.takeDamage(tom.getAttackDamage());
	jerry.highFivesGuys();
	eric.beRepaired(50);
	eric.highFivesGuys();
	eric.guardGate();
	eric.whoAmI();
	eric.attack("Tom");
	if (eric.getEnergyPoint() && eric.getHitPoint())
		tom.takeDamage(eric.getAttackDamage());

	// Status
	std::cout << jerry << " energy : " << jerry.getEnergyPoint()
			  << " - life : " << jerry.getHitPoint() << std::endl;
	std::cout << tom << " energy : " << tom.getEnergyPoint()
			  << " - life : " << tom.getHitPoint() << std::endl;
	std::cout << bob << " energy : " << bob.getEnergyPoint()
			  << " - life : " << bob.getHitPoint() << std::endl;
	std::cout << eric << " energy : " << eric.getEnergyPoint()
			  << " - life : " << eric.getHitPoint() << std::endl;

	return (0);
}