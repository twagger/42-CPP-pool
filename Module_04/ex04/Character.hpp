/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 09:26:30 by twagner           #+#    #+#             */
/*   Updated: 2022/02/27 11:25:42 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <iostream>
# define INVENTORY_SIZE 4

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
		AMateria	*_inventory[INVENTORY_SIZE];
};

#endif
