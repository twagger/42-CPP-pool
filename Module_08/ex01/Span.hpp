/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:00:14 by twagner           #+#    #+#             */
/*   Updated: 2022/03/26 14:30:39 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>

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
		void	addNumber(std::vector<int>::iterator it, std::vector<int>::iterator ite);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

	private:
		Span(void);
		int	*_arr;
		int _current_level;
		int	_max_level;
};

#endif