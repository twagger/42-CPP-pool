/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:53:26 by twagner           #+#    #+#             */
/*   Updated: 2022/03/27 10:00:01 by twagner          ###   ########.fr       */
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
	std::vector<int>			vect(42);
	std::vector<int>::iterator	it;
	std::generate_n(vect.begin(), 42, UniqueNumber);
	try
	{
		it = easyfind(vect, 8);
		std::cout << "I found it : " << *it << std::endl;
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
		it = easyfind(vect, 50);
		std::cout << "I found it : " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	// TEST 3
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ List OK : find 42 ]--- \033[0m" << std::endl;
	std::list<int>				lst(10);
	std::list<int>::iterator	it2;
	std::fill_n(lst.begin(), 10, 43);
	std::fill_n(lst.begin(), 1, 42);
	try
	{
		it2 = easyfindWithControl(lst, 42, NULL);
		std::cout << "I found it : " << *it2 << std::endl;
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
		it2 = easyfind(lst, 41);
		std::cout << "I found it : " << *it2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	// TEST 5
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Deque OK : find 50 ]--- \033[0m" << std::endl;
	std::deque<int>				deck(8);
	std::deque<int>::iterator	it3;
	std::generate_n(deck.begin(), 10, UniqueNumber);
	try
	{
		it3 = easyfindWithControl(deck, 50, NULL);
		std::cout << "I found it : " << *it3 << std::endl;
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
		it3 = easyfindWithControl(deck, 41, NULL);
		std::cout << "I found it : " << *it3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	// TEST 7
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Stack test : KO (stack has no iterators) ]--- \033[0m" << std::endl;
	std::stack<int>	stk;
	int				*it4;
	stk.push(5);
	stk.push(8);
	stk.push(-1);
	try
	{
		it4 = easyfindWithControl(stk, 8, NULL);
		std::cout << "I found it : " << *it4 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	// END OF MAIN
	std::cout << std::endl;
	return (0);
}
