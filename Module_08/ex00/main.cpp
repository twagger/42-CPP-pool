/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:53:26 by twagner           #+#    #+#             */
/*   Updated: 2022/03/26 14:19:41 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>

int main(void)
{
	int	i;
	
	// TEST 1
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Vector OK : find 8 ]--- \033[0m" << std::endl;
	std::vector<int>	vect;
	vect.push_back(5);
	vect.push_back(8);
	vect.push_back(-1);
	try
	{
		i = easyfind(vect, 8);
		std::cout << i << std::endl;
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
		i = easyfind(vect, 50);
		std::cout << i << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	// TEST 3
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ List OK : find 42 ]--- \033[0m" << std::endl;
	std::list<int>	lst;
	lst.push_back(43);
	lst.push_back(43);
	lst.push_back(42);
	lst.push_back(43);
	lst.push_back(43);
	lst.push_back(42);
	lst.push_back(42);
	try
	{
		i = easyfindWithControl(lst, 42, NULL);
		std::cout << i << std::endl;
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
		i = easyfind(lst, 41);
		std::cout << i << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	// TEST 5
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Deque OK : find 42 ]--- \033[0m" << std::endl;
	std::deque<int>	deck;
	deck.push_back(43);
	deck.push_back(43);
	deck.push_back(42);
	deck.push_back(43);
	deck.push_front(48);
	deck.push_front(48);
	deck.push_front(48);
	deck.push_front(48);
	try
	{
		i = easyfindWithControl(deck, 42, NULL);
		std::cout << i << std::endl;
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
		i = easyfindWithControl(deck, 41, NULL);
		std::cout << i << std::endl;
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
		i = easyfindWithControl(stk, 8, NULL);
		std::cout << i << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	// END OF MAIN
	std::cout << std::endl;
	return (0);
}
