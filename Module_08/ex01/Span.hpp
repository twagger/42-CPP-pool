/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:00:14 by twagner           #+#    #+#             */
/*   Updated: 2022/07/25 20:42:16 by twagner          ###   ########.fr       */
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
		int	getValue(unsigned int i) const;

		// Member functions
		void	addNumber(int number);
		void	addNumber(std::vector<int>::iterator it, std::vector<int>::iterator ite);
		int		shortestSpan(void);
		int		longestSpan(void) const;

		// Exceptions
		class FullSpanException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class OneElementException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		
		class EmptySizeException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		
		class OutOfRangeException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

	private:
		Span(void);
		std::vector<int>	_arr;
		long unsigned int	_max;
};

#endif
