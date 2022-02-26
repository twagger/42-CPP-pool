/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:43:50 by twagner           #+#    #+#             */
/*   Updated: 2022/02/26 16:14:01 by twagner          ###   ########.fr       */
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
		Brain(Brain	const &src);
		~Brain(void);

		// Operators override
		Brain	&operator=(Brain const &rhs);

		// Member functions
		int		addIdea(const std::string idea);
		int		removeIdea(int num);
		void	displayIdeas(void) const;

	private:
		std::string	_ideas[100];
};

#endif