/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:57:38 by twagner           #+#    #+#             */
/*   Updated: 2022/03/19 15:46:53 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template< typename T>
class Array
{
	public:
		// Constructors and destructor
		Array(void);
		Array(unsigned int n);
		Array(const Array &src);
		~Array(void);

		// Operator overload
		Array	&operator=(const Array &rhs);
		T		&operator[](unsigned int i);

		// Accessors
		T				&getItem(unsigned int i) const;
		unsigned int	getSize(void) const;

		// Member functions
		unsigned int	size(void) const;
		
	private:
		T				*_array;
		unsigned int	_size;
		bool			_isAllocated;
};

# include "Array.tpp"

#endif
