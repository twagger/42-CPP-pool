/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:00:14 by twagner           #+#    #+#             */
/*   Updated: 2022/03/25 13:17:06 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

class Span
{
	public:
		// Constructors and destructor
		Span(unsigned int N);
		Span(const Span &src);
		~Span();

		// Operators overload
		Span	&operator=(const Span &rhs);

		// Accessors
		int	getMaxLevel(void) const;
		int	getCurrentLevel(void) const;
		int	getValue(int) const;

		// Member functions
		void	addNumber(int number);
		void	addNumber(int *it, int *it_end);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

	private:
		Span(void);
		int	*_arr;
		int _current_level;
		int	_max_level;
};

#endif