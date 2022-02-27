/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:05:26 by twagner           #+#    #+#             */
/*   Updated: 2022/02/27 10:07:50 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		// Constructors and destructor
		MateriaSource(void);
		MateriaSource(MateriaSource const &src);
		~MateriaSource(void);

		// Operator overload
		MateriaSource	&operator=(MateriaSource const &rhs);
};
