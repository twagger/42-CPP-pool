/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:00:12 by twagner           #+#    #+#             */
/*   Updated: 2022/02/11 13:17:12 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"
# include <iostream>

class HumanA
{
	private:
		std::string	_name;
		Weapon		_weapon;
	public:
		HumanA(std::string name, Weapon weapon);
		~HumanA();

		void	attack(void);
};

#endif
