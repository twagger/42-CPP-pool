/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:02:00 by twagner           #+#    #+#             */
/*   Updated: 2022/02/25 11:10:11 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
	public:
		// Constructors and destructor
		Brain(void);
		Brain(Brain const &src);
		virtual	~Brain(void);

		// operator overload
		Brain	&operator=(Brain const &rhs);

	private:
		std::string	ideas[100];
};

#endif