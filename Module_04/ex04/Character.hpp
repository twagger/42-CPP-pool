/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 09:26:30 by twagner           #+#    #+#             */
/*   Updated: 2022/02/27 10:50:17 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <iostream>

class Character : public ICharacter
{
	public:
		// Constructors and destructor
		Character(void);
		Character(std::string const &name);
		Character(Character const &src);
		~Character(void);

		// Operator overload
		Character	&operator=(Character const &rhs);

		// Member functions
		virtual std::string const	&getName() const;
		virtual void				equip(AMateria *m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter &target);
	
	private:
		std::string	_name;
		AMateria	*_inventory[4] = { NULL };
};

#endif