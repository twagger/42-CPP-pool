/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:14:41 by twagner           #+#    #+#             */
/*   Updated: 2022/02/18 16:47:22 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
	public:
		// Constructors and destructor
		ClapTrap(void);
		ClapTrap(int value);
		ClapTrap(float value);
		ClapTrap(ClapTrap const &src);
		~ClapTrap(void);

		// operator overload
		ClapTrap	&operator=(ClapTrap const &rhs);

		// member functions
		int				toInt(void)	const;

	private:
		int					_value;
		static int const	_nbBits;
};

std::ostream	&operator<<(std::ostream &o, ClapTrap const &i);

#endif
