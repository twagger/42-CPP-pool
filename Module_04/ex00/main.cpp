/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:12:03 by twagner           #+#    #+#             */
/*   Updated: 2022/03/01 15:47:03 by twagner          ###   ########.fr       */
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
	std::cout << *j << " : ";
	i->makeSound();
	std::cout << *i << " : ";
	j->makeSound();
	std::cout << *meta << " : ";
	meta->makeSound();

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "| Animals should output Wrong animals sounds |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << *k << " : ";
	k->makeSound();
	std::cout << *l << " : ";
	l->makeSound();

	delete meta;
	delete j;
	delete i;
	delete k;
	delete l;

	return (0);
}