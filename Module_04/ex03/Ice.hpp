/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:14:41 by twagner           #+#    #+#             */
/*   Updated: 2022/02/27 10:29:03 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ICE_HPP
# define ICE_HPP
# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		// Constructors and destructor
		Ice(void);
		Ice(Ice const &src);
		~Ice(void);

		// Operator overload
		Ice	&operator=(Ice const &);
		
		// Member functions
		Ice		*clone(void) const;
		void	use(ICharacter &target);
};

#endif
