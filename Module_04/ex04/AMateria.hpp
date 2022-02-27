/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:14:41 by twagner           #+#    #+#             */
/*   Updated: 2022/02/27 12:04:38 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	public:
		// Constructors and destructor
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(AMateria const &src);
		~AMateria(void);

		// Operator overload
		AMateria	&operator=(AMateria const &rhs);

		// Member functions
		std::string const	&getType() const; //Returns the materia type
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
	
	protected:
		std::string	_type;
};

#endif