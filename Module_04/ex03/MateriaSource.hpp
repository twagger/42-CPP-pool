/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:05:26 by twagner           #+#    #+#             */
/*   Updated: 2022/02/27 12:03:45 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#define STOCK_SIZE 4

class MateriaSource : public IMateriaSource
{
	public:
		// Constructors and destructor
		MateriaSource(void);
		MateriaSource(MateriaSource const &src);
		~MateriaSource(void);

		// Operator overload
		MateriaSource	&operator=(MateriaSource const &rhs);

		// Member functions
		void		learnMateria(AMateria *m);
		AMateria	*createMateria(std::string const &type);

	private:
		AMateria	*_stock[STOCK_SIZE];
};
