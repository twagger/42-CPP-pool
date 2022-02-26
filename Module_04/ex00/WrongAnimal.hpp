/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:14:41 by twagner           #+#    #+#             */
/*   Updated: 2022/02/26 12:36:31 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
	public:
		// Constructors and destructor
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const &src);
		virtual ~WrongAnimal(void);

		// operator overload
		WrongAnimal	&operator=(WrongAnimal const &rhs);

		// accessors
		std::string	getType(void) const;

		// member functions
		void	makeSound(void) const;

	protected:
		std::string	_type;
};

std::ostream	&operator<<(std::ostream &o, WrongAnimal const &i);

#endif
