/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:12:03 by twagner           #+#    #+#             */
/*   Updated: 2022/02/19 12:33:29 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	tom("Tom");
	ScavTrap	jerry("Jerry");

	tom.attack("Jerry");
	if (tom.getEnergyPoint() && tom.getHitPoint())
		jerry.takeDamage(tom.getAttackDamage());
	tom.guardGate();
	jerry.beRepaired(20);
	jerry.attack("Tom");
	if (jerry.getEnergyPoint() && jerry.getHitPoint())
		tom.takeDamage(jerry.getAttackDamage());
	jerry.attack("Tom");
	if (jerry.getEnergyPoint() && jerry.getHitPoint())
		tom.takeDamage(jerry.getAttackDamage());
	jerry.attack("Tom");
	if (jerry.getEnergyPoint() && jerry.getHitPoint())
		tom.takeDamage(jerry.getAttackDamage());
	jerry.attack("Tom");
	if (jerry.getEnergyPoint() && jerry.getHitPoint())
		tom.takeDamage(jerry.getAttackDamage());
	jerry.attack("Tom");
	if (jerry.getEnergyPoint() && jerry.getHitPoint())
		tom.takeDamage(jerry.getAttackDamage());
	jerry.attack("Tom");
	if (jerry.getEnergyPoint() && jerry.getHitPoint())
		tom.takeDamage(jerry.getAttackDamage());
	tom.attack("Jerry");
	if (tom.getEnergyPoint() && tom.getHitPoint())
		jerry.takeDamage(tom.getAttackDamage());

	std::cout << jerry << " energy : " << jerry.getEnergyPoint()
			  << " - life : " << jerry.getHitPoint() << std::endl;
	std::cout << tom << " energy : " << tom.getEnergyPoint()
			  << " - life : " << tom.getHitPoint() << std::endl;


	return (0);
}