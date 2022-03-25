/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:53:26 by twagner           #+#    #+#             */
/*   Updated: 2022/03/25 12:49:52 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main(void)
{
	// TEST 1
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Span with 5 ints ]--- \033[0m" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	// TEST 2
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Shortest span ]--- \033[0m" << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	
	// TEST 3
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Longest span ]--- \033[0m" << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// TEST 4
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Trying to insert a value in a full span ]--- \033[0m" << std::endl;
	try
	{
		sp.addNumber(42);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	// TEST 5
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Span with 0 ints ]--- \033[0m" << std::endl;
	Span sp2 = Span(0);
	try
	{
		sp2.addNumber(6);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	// TEST 6
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Accessing an index [5] on a span with 3 values ]--- \033[0m" << std::endl;
	Span sp3 = Span(3);
	std::cout << "value at index [0] : " << sp3.getValue(0) << std::endl;
	try
	{
		std::cout << "value at index [5] : ";
		sp3.getValue(5);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	// END OF MAIN
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ End of program ]--- \033[0m" << std::endl;
	return (0);
}
