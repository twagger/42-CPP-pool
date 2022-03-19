/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Litteral.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:14:00 by twagner           #+#    #+#             */
/*   Updated: 2022/03/19 10:39:45 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITTERAL_HPP
# define LITTERAL_HPP
# include <iostream>

class Litteral
{
	public:
		// Constructors and destructor
		Litteral(char *litteral);
		Litteral(Litteral const &src);
		~Litteral(void);

		// operator overload
		Litteral	&operator=(Litteral const &rhs);

		// member functions
		char	*getLitteral(void) const;
		bool	isNumber(void) const;
		bool	isNonNumeric(void) const;
		char	toChar(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;
		double	toDouble(void) const;

		// exceptions
		class ImpossibleConversionException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class NonDisplayableException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class OverflowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		
		class UnderflowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

	private:
		Litteral(void);
		char	*_litteral;
};

typedef std::string (Litteral::*Converter)(void) const;

#endif
