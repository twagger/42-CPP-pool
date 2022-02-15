/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:14:41 by twagner           #+#    #+#             */
/*   Updated: 2022/02/15 15:11:47 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	public:
		// Constructors and destructor
		Fixed(void);
		Fixed(int value);
		Fixed(float value);
		Fixed(Fixed const &src);
		~Fixed(void);

		// operator overload
		Fixed	&operator=(Fixed const &rhs);
		Fixed	operator+(Fixed const &rhs) const;
		Fixed	operator-(Fixed const &rhs) const;
		Fixed	operator*(Fixed const &rhs) const;
		Fixed	operator/(Fixed const &rhs) const;
		Fixed	&operator++(void);
		Fixed	operator++(int value);
		Fixed	&operator--(void);
		Fixed	operator--(int value);
		bool	operator>(Fixed const &rhs) const;
		bool	operator<(Fixed const &rhs) const;
		bool	operator>=(Fixed const &rhs) const;
		bool	operator<=(Fixed const &rhs) const;
		bool	operator==(Fixed const &rhs) const;
		bool	operator!=(Fixed const &rhs) const;

		// member functions
		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int				toInt(void)	const;
		static Fixed	&min(Fixed &f1, Fixed &f2);
		static Fixed	min(Fixed const &f1, Fixed const &f2);
		static Fixed	&max(Fixed &f1, Fixed &f2);
		static Fixed	max(Fixed const &f1, Fixed const &f2);

	private:
		int					_value;
		static int const	_nbBits;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &i);

#endif
