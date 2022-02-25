/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:12:03 by twagner           #+#    #+#             */
/*   Updated: 2022/02/25 10:46:52 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal		*meta = new Animal();
	const Animal		*j = new Dog();
	const Animal		*i = new Cat();
	const WrongAnimal	*k = new WrongAnimal();
	const WrongAnimal	*l = new WrongCat();

	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "| Animals should output cat and dog sounds |" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "| Animals should output Wrong animals sounds |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl;
	k->makeSound();
	l->makeSound();

	delete meta;
	delete j;
	delete i;
	delete k;
	delete l;

	return (0);
}