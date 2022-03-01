/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:22:59 by twagner           #+#    #+#             */
/*   Updated: 2022/03/01 09:18:50 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	public:
		// Constructors and destructor
		Cat(void);
		Cat(Cat const &src);
		~Cat(void);

		// operator overload
		Cat	&operator=(Cat const &rhs);

		// member functions	
		void	makeSound(void) const;
		int		addIdea(const std::string idea);
		int		removeIdea(int num);
		void	displayIdeas(void) const;
		Brain	*getBrain(void) const;

	private:
		Brain	*_brain;
};

#endif