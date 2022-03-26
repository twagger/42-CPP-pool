/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:53:26 by twagner           #+#    #+#             */
/*   Updated: 2022/03/26 17:24:54 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <stack>

int UniqueNumber(void)
{
	static int	current;

	return (++current);
}

int main(void)
{
	// TEST 1
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Vector OK : find 8 ]--- \033[0m" << std::endl;
	std::vector<int>	vect(42);
	std::generate_n(vect.begin(), 42, UniqueNumber);
	try
	{
		easyfind(vect, 8);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	
	// TEST 2
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Vector KO : find 50 ]--- \033[0m" << std::endl;
	try
	{
		easyfind(vect, 50);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	// TEST 3
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ List OK : find 42 ]--- \033[0m" << std::endl;
	std::list<int>	lst(10);
	std::fill_n(lst.begin(), 9, 43);
	std::fill_n(lst.begin(), 1, 42);
	try
	{
		easyfindWithControl(lst, 42, NULL);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	// TEST 4
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ List KO : find 41 ]--- \033[0m" << std::endl;
	try
	{
		easyfind(lst, 41);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	// TEST 5
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Deque OK : find 50 ]--- \033[0m" << std::endl;
	std::deque<int>	deck(8);
	std::generate_n(deck.begin(), 10, UniqueNumber);
	try
	{
		easyfindWithControl(deck, 50, NULL);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	// TEST 6
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Deque KO : find 41 ]--- \033[0m" << std::endl;
	try
	{
		easyfindWithControl(deck, 41, NULL);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	// TEST 7
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Stack test : KO (stack has no iterators) ]--- \033[0m" << std::endl;
	std::stack<int>	stk;
	stk.push(5);
	stk.push(8);
	stk.push(-1);
	try
	{
		easyfindWithControl(stk, 8, NULL);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	// END OF MAIN
	std::cout << std::endl;
	return (0);
}
