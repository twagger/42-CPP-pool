/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:31:59 by twagner           #+#    #+#             */
/*   Updated: 2022/03/15 17:39:02 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
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
			break;
		case 1:
			break;
		case 2:
			break;
		default:
			break;
	}
}

void identify(Base* p);

void identify(Base& p);

int	main(void)
{
	Base	base;
	A		a;
	B		b;
	C		c;


	return (0);
}
