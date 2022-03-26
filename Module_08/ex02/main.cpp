/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:53:26 by twagner           #+#    #+#             */
/*   Updated: 2022/03/26 17:42:24 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(void)
{
	// TEST 1
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Mutant stack standard tests ]--- \033[0m" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	// TEST 2
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Creating a std stack from mutant ]--- \033[0m" << std::endl;
	try
	{
		std::stack<int> s(mstack);
		std::cout << "It works fine" << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	
	// TEST 3
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Same as test 1 but with a list (same output expected) ]--- \033[0m" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator it2 = lst.begin();
	std::list<int>::iterator ite2 = lst.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	
	// TEST 4
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Mutant stack char tests ]--- \033[0m" << std::endl;
	MutantStack<char> mstack2;
	mstack2.push('s');
	mstack2.push('o');
	std::cout << mstack2.top() << std::endl;
	mstack2.pop();
	std::cout << mstack2.size() << std::endl;
	mstack2.push('a');
	mstack2.push('l');
	mstack2.push('u');
	mstack2.push('t');
	MutantStack<char>::iterator it3 = mstack2.begin();
	MutantStack<char>::iterator ite3 = mstack2.end();
	++it3;
	--it3;
	while (it3 != ite3)
	{
		std::cout << *it3 << std::endl;
		++it3;
	}

	// END OF PROGRAM
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ End of program ]--- \033[0m" << std::endl;
	return (0);
}
