/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 09:26:30 by twagner           #+#    #+#             */
/*   Updated: 2022/03/01 16:20:11 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include <iostream>
# define INVENTORY_SIZE 4

class AMateria;

class Character : public ICharacter
{
	public:
		// Constructors and destructor
		Character(void);
		Character(std::string const &name);
		Character(Character const &src);
		virtual ~Character(void);

		// Operator overload
		Character	&operator=(Character const &rhs);

		// Member functions
		std::string const	&getName() const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
	
	private:
		std::string	_name;
		AMateria	*_inventory[INVENTORY_SIZE];
};

#endif
