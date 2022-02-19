/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:14:41 by twagner           #+#    #+#             */
/*   Updated: 2022/02/19 15:19:55 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
	public:
		// Constructors and destructor
		Animal(void);
		Animal(std::string type);
		Animal(Animal const &src);
		~Animal(void);

		// operator overload
		Animal	&operator=(Animal const &rhs);

		// accessors
		std::string	getType(void) const;

		// member functions
		void	makeSound(void) const;

	protected:
		std::string	_type;
};

std::ostream	&operator<<(std::ostream &o, Animal const &i);

#endif
