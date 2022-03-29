/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:53:26 by twagner           #+#    #+#             */
/*   Updated: 2022/03/29 09:38:16 by twagner          ###   ########.fr       */
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
	std::cout << "\033[1;35m ---[ 1. Vector OK : find 8 ]--- \033[0m" << std::endl;
	std::vector<int>					vect(42,0);
	std::vector<int>::iterator			it;
	std::generate_n(vect.begin(), 42, UniqueNumber);
	try
	{
		easyfind(vect, 8);
		// test with an iterator return
		// it = easyfind2(vect, 8);
		// std::cout << "value : " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	
	// TEST 2
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ 2. Vector KO : find 50 ]--- \033[0m" << std::endl;
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
	std::cout << "\033[1;35m ---[ 3. List OK : find 42 ]--- \033[0m" << std::endl;
	std::list<int>					lst(10);
	std::fill_n(lst.begin(), 10, 43);
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
	std::cout << "\033[1;35m ---[ 4. List KO : find 41 ]--- \033[0m" << std::endl;
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
	std::cout << "\033[1;35m ---[ 5. Deque OK : find 50 ]--- \033[0m" << std::endl;
	std::deque<int>					deck(8);
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
	std::cout << "\033[1;35m ---[ 6. Deque KO : find 41 ]--- \033[0m" << std::endl;
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
	std::cout << "\033[1;35m ---[ 7. Stack test : KO (stack has no iterators) ]--- \033[0m" << std::endl;
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
