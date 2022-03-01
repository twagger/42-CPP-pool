/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:12:03 by twagner           #+#    #+#             */
/*   Updated: 2022/03/01 17:20:55 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main(void)
{
	std::cout << "-----------------" << std::endl;
	std::cout << "| MATERIA LEARN  |" << std::endl;
	std::cout << "-----------------" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << ">>>> ERROR TESTS <<<<" << std::endl;
	src->learnMateria(new Cure());
	src->learnMateria(NULL);
	
	std::cout << "-----------------" << std::endl;
	std::cout << "| <ME> CREATION |" << std::endl;
	std::cout << "-----------------" << std::endl;
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << ">>>> UNEQUIP TEST <<<<" << std::endl;
	me->unequip(0);
	delete tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << ">>>> ERROR TESTS <<<<" << std::endl;
	tmp = src->createMateria("toto");
	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;
	me->unequip(5);

	std::cout << "------------------" << std::endl;
	std::cout << "| <BOB> CREATION |" << std::endl;
	std::cout << "------------------" << std::endl;
	ICharacter* bob = new Character("bob");

	std::cout << "--------------------" << std::endl;
	std::cout << "| <ME> MATERIA USE |" << std::endl;
	std::cout << "--------------------" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "--------------------" << std::endl;
	std::cout << "|     CLEANING     |" << std::endl;
	std::cout << "--------------------" << std::endl;
	delete bob;
	delete me;
	delete src;
	
	return (0);
}
