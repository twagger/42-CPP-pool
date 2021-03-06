/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:57:35 by twagner           #+#    #+#             */
/*   Updated: 2022/02/26 12:03:31 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		// Constructors and destructor
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &src);
		~DiamondTrap(void);

		// member functions
		using			ScavTrap::attack;
		void			whoAmI(void) const;
		std::string		getName(void) const;
	
	private:
		std::string	_name;
};

std::ostream	&operator<<(std::ostream &o, DiamondTrap const &i);

#endif