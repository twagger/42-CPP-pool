/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:14:41 by twagner           #+#    #+#             */
/*   Updated: 2022/02/15 10:13:13 by twagner          ###   ########.fr       */
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

		// member functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void)	const;

	private:
		int					_value;
		static int const	_nbBits;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &i);

#endif
