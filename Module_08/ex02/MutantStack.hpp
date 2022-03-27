/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:00:14 by twagner           #+#    #+#             */
/*   Updated: 2022/03/27 23:21:19 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>
# include <iterator>

template< typename T >
class MutantStack : public std::stack<T>
{
	public:
		// Constructors and destructor
		MutantStack(void);
		MutantStack(const MutantStack &src);
		~MutantStack();

		// Operators overload
		MutantStack	&operator=(const MutantStack &rhs);

		// Iterators
		typedef typename std::stack<T>::container_type::iterator		iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
		
		iterator	begin(void) {return (this->c.begin());};
		iterator	end(void) {return (this->c.end());};
		const_iterator	begin(void) const {return (this->c.begin());};
		const_iterator	end(void) const {return (this->c.end());};
};

# include "MutantStack.tpp"

#endif