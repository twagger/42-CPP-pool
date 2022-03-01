/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:12:03 by twagner           #+#    #+#             */
/*   Updated: 2022/03/01 16:01:28 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#define NB_ANIMALS 6

int main(void)
{
	int		i;
	Animal	*arch[NB_ANIMALS];

	std::cout << "-----------------" << std::endl;
	std::cout << "|   ARCH TEST   |" << std::endl;
	std::cout << "-----------------" << std::endl;
	/*
	** Creation of every cat and dog in the arch
	*/
	std::cout << "** Creation of " << NB_ANIMALS / 2 << " Cats and "
			  << NB_ANIMALS / 2 << " Dogs" << std::endl;
	i = 0;
	while (i < NB_ANIMALS / 2)
		arch[i++] = new Dog();
	while (i < NB_ANIMALS)
		arch[i++] = new Cat();
	/*
	** Deletion of every animal in the arch
	*/
	std::cout << "** Deletion of all animals in the arch. " << std::endl;
	i = -1;
	while (++i < NB_ANIMALS)
		delete arch[i];
	
	std::cout << "-----------------" << std::endl;
	std::cout << "|  BRAIN TEST   |" << std::endl;
	std::cout << "-----------------" << std::endl;
	// Creating a new cat with 2 ideas
	Cat henry;
	henry.addIdea("sleep");
	henry.addIdea("eat");
	// Copying this animal to create another one
	Cat gaston(henry);
	// Removing an idea and adding a new one
	gaston.removeIdea(1);
	gaston.addIdea("play");
	// Displaying both cats ideas to show that they use a different brain
	std::cout << "Henry ideas :" << std::endl;
	henry.displayIdeas();
	std::cout << "Gaston ideas :" << std::endl;
	gaston.displayIdeas();
	
	return (0);
}