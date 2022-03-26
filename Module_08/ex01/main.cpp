/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:53:26 by twagner           #+#    #+#             */
/*   Updated: 2022/03/26 14:45:23 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

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
	
	// TEST 7
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Inserting 10000 values using 1 command ]--- \033[0m" << std::endl;
	Span						sp4 = Span(10000);
	std::vector<int>			arr[10000];
	// fill the vector
	for (int i = 0; i < 10000; ++i)
		arr->push_back(i);
	// use an iterator to fill the Span from the vector
	sp4.addNumber(arr->begin(), arr->end());
	std::cout << "value at index [586] : " << sp4.getValue(586) << std::endl;
	std::cout << "value at index [5] : " << sp4.getValue(5) << std::endl;
	std::cout << "Shortest span : " << sp4.shortestSpan() << std::endl;
	std::cout << "Longest span : " << sp4.longestSpan() << std::endl;


	// END OF MAIN
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ End of program ]--- \033[0m" << std::endl;
	return (0);
}
