/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:17:16 by twagner           #+#    #+#             */
/*   Updated: 2022/02/26 17:04:55 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		// Constructors and destructor
		Dog(void);
		Dog(Dog const &src);
		~Dog(void);

		// member functions
		void	makeSound(void) const;
		int		addIdea(const std::string idea);
		int		removeIdea(int num);
		void	displayIdeas(void) const;
		Brain	*getBrain(void) const;

	private:
		Brain	*_brain;	
};

#endif