/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:53:26 by twagner           #+#    #+#             */
/*   Updated: 2022/03/27 16:03:41 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

int UniqueNumber(void)
{
	static int	current;

	return (++current);
}

int main(void)
{
	// TEST 1
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ 1. Span with 5 ints ]--- \033[0m" << std::endl;
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	// TEST 2
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ 2. Span copy from another one ]--- \033[0m" << std::endl;
	Span sp9(sp);
	std::cout << "Value check : base[2]=" << sp.getValue(2) << " | copy[2]=" << sp9.getValue(2) << std::endl;

	// TEST 3
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ 3. Shortest span ]--- \033[0m" << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	
	// TEST 4
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ 4. Longest span ]--- \033[0m" << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// TEST 5
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ 5. Trying to insert a value in a full span ]--- \033[0m" << std::endl;
	try
	{
		sp.addNumber(42);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// TEST 6
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ 6. Try to get longestSpan on an empty sized span ]--- \033[0m" << std::endl;
	Span sp2(0);
	try
	{
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
 
 	// TEST 7
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ 7. Try to add a number in an empty sized span ]--- \033[0m" << std::endl;
	try
	{
		sp2.addNumber(6);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// TEST 8
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ 8. Try to get shortest span in a 1 number span ]--- \033[0m" << std::endl;
	Span	sp7(1);
	sp7.addNumber(6);
	try
	{
		std::cout << sp7.shortestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	// TEST 9
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ 9. Try to get longest span in a 1 number span ]--- \033[0m" << std::endl;
	try
	{
		std::cout << sp7.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// TEST 10
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ 10. Accessing an index [5] on a span with 3 values ]--- \033[0m" << std::endl;
	Span sp3(3);
	try
	{
		std::cout << "value at index [5] : ";
		sp3.getValue(5);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	// TEST 11
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ 11. Inserting 10000 values using 1 command ]--- \033[0m" << std::endl;
	Span				sp4(10000);
	std::vector<int>	arr(10000);
	// fill the vector
	std::generate_n(arr.begin(), 10000, UniqueNumber);
	sp4.addNumber(arr.begin(), arr.end());
	std::cout << "value at index [586] : " << sp4.getValue(586) << std::endl;
	std::cout << "value at index [5] : " << sp4.getValue(5) << std::endl;
	std::cout << "Shortest span : " << sp4.shortestSpan() << std::endl;
	std::cout << "Longest span : " << sp4.longestSpan() << std::endl;

	// TEST 12
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ 12. Inserting 100000 values using 1 command ]--- \033[0m" << std::endl;
	Span				sp5(100000);
	std::vector<int>	arr2(100000);
	// fill the vector
	std::generate_n(arr2.begin(), 100000, UniqueNumber);
	sp5.addNumber(arr2.begin(), arr2.end());
	std::cout << "value at index [5086] : " << sp5.getValue(5086) << std::endl;
	std::cout << "value at index [88888] : " << sp5.getValue(88888) << std::endl;
	std::cout << "Shortest span : " << sp5.shortestSpan() << std::endl;
	std::cout << "Longest span : " << sp5.longestSpan() << std::endl;

	// END OF MAIN
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ End of program ]--- \033[0m" << std::endl;
	return (0);
}
