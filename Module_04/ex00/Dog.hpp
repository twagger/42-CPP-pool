/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:17:16 by twagner           #+#    #+#             */
/*   Updated: 2022/03/01 09:02:53 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		// Constructors and destructor
		Dog(void);
		Dog(Dog const &src);
		~Dog(void);

		// operator overload
		Dog	&operator=(Dog const &rhs);

		// member functions
		void	makeSound(void) const;

};

#endif