/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:00:14 by twagner           #+#    #+#             */
/*   Updated: 2022/03/25 16:47:11 by twagner          ###   ########.fr       */
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
		class iterator : public std::iterator<std::input_iterator_tag, T>
		{
			public:
				// constructors
  				iterator(int* x) : p(x) {}
  				iterator(const iterator &it) : p(it.p) {}

				// operators overload  
  				iterator	&operator++(void) {++this->p;return *this;}
  				iterator 	operator++(int) {iterator tmp(*this); operator++(); return tmp;}
  				iterator	&operator--(void) {--this->p;return *this;}
  				iterator 	operator--(int) {iterator tmp(*this); operator--(); return tmp;}
  				bool 		operator==(const iterator& rhs) const {return this->p == rhs.p;}
  				bool 		operator!=(const iterator& rhs) const {return this->p != rhs.p;}
  				int			&operator*(void) {return *(this->p);}
				
				// attributes
				int 		*p;
		};

		// Member functions
		MutantStack<T>::iterator	end(void) {return (&this->top() + 1);};
		MutantStack<T>::iterator	begin(void) {return ((&this->top() + 1) - this->size());};
};

# include "MutantStack.tpp"

#endif