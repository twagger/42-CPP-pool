/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:12:03 by twagner           #+#    #+#             */
/*   Updated: 2022/02/15 16:16:13 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	Fixed		c(b);

	std::cout << "a        : " << a << std::endl;
	std::cout << "++a      : " << ++a << std::endl;
	std::cout << "a        : " << a << std::endl;
	std::cout << "a++      : " << a++ << std::endl;
	std::cout << "a        : " << a << std::endl;
	std::cout << "b        : " << b << std::endl;
	std::cout << "max(a,b) : " << Fixed::max(a, b) << std::endl;
	std::cout << "min(a,c) : " << Fixed::min(a, c) << std::endl;
	std::cout << "c++      : " << c++ << std::endl;
	std::cout << "b        : " << b << std::endl;

	return (0);
}