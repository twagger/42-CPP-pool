/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:27:48 by twagner           #+#    #+#             */
/*   Updated: 2022/03/25 16:45:52 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructors and destructor
*/
template< typename T >
MutantStack<T>::MutantStack(void) : std::stack<T>()
{
	if (!SILENT)	
		std::cout << ">> + MutantStack default constructor called" << std::endl;
}

template< typename T >
MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>()
{
	if (!SILENT)	
		std::cout << ">> + MutantStack copy constructor called" << std::endl;	
	*this = src;
}

template< typename T >
MutantStack<T>::~MutantStack()
{
	if (!SILENT)	
		std::cout << ">> - MutantStack destructor called" << std::endl;
}

/*
** Operators overload
*/

template< typename T >
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack<T> &rhs)
{
	if (!SILENT)	
		std::cout << ">> = MutantStack assignment operator called" << std::endl;
	return (*this);
}
