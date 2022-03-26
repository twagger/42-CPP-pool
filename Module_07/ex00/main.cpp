/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:14:00 by twagner           #+#    #+#             */
/*   Updated: 2022/03/26 09:44:31 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main(void)
{
	// TEST 1
	std::cout << "\033[1;35m ---[ 1. Test from the subject ]--- \033[0m" << std::endl;
	int a = 2;
	int b = 3;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "swap" << std::endl << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "swap" << std::endl << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	// TEST 2
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ 2. Test with double ]--- \033[0m" << std::endl;
	double e = 42.8;
	double f = 37.98;
	std::cout << "e = " << e << ", f = " << f << std::endl;
	::swap( e, f );
	std::cout << "swap" << std::endl << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

	// TEST 3
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ 3. Test with char ]--- \033[0m" << std::endl;
	char g = '*';
	char h = 'f';
	std::cout << "g = " << g << ", h = " << h << std::endl;
	::swap( g, h );
	std::cout << "swap" << std::endl << "g = " << g << ", h = " << h << std::endl;
	std::cout << "min( g, h ) = " << ::min( g, h ) << std::endl;
	std::cout << "max( g, h ) = " << ::max( g, h ) << std::endl;

	return (0);
}
