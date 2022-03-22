/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:31:59 by twagner           #+#    #+#             */
/*   Updated: 2022/03/22 12:30:44 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	int	rnd_out;

	std::srand(std::time(NULL));
	rnd_out = std::rand() % 3;
	switch (rnd_out)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			break;
	}
	return (NULL);
}

void identify(Base *p)
{
	A	*a;
	B	*b;
	C	*c;

	a = dynamic_cast<A *>(p);
	b = dynamic_cast<B *>(p);
	c = dynamic_cast<C *>(p);
	if (a != NULL)
		std::cout << "A" << std::endl;
	else if (b != NULL)
		std::cout << "B" << std::endl;
	else if (c != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A	&a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(std::exception &){}
	try
	{
		B	&b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch(std::exception &){}
	try
	{
		C	&c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch(std::exception &){}
}

int	main(void)
{
	Base	*ptr;

	// TEST 1
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Generating a random A, B, or C ]--- \033[0m" << std::endl;
	ptr = generate();

	// TEST 2
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Identifying the real type of ptr ]--- \033[0m" << std::endl;
	identify(ptr);

	// TEST 3
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ Identifying the real type of ref ]--- \033[0m" << std::endl;
	Base	&ref = *ptr;
	identify(ref);

	// END OF MAIN
	std::cout << std::endl;
	std::cout << "\033[1;35m >>> End of main <<<\033[0m" << std::endl;
	delete ptr;
	return (0);
}
