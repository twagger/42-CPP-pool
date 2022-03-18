/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:28:38 by twagner           #+#    #+#             */
/*   Updated: 2022/03/18 10:33:32 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include <iostream>
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

A::A(void)
{
	if (!SILENT)
		std::cout << ">> +🇦 constructor called" << std::endl;
}

A::~A(void)
{
	if (!SILENT)
		std::cout << ">> -🇦 destructor called" << std::endl;
}
