/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:32:16 by twagner           #+#    #+#             */
/*   Updated: 2022/03/18 10:33:10 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"
#include <iostream>
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

C::C(void)
{
	if (!SILENT)
		std::cout << ">> +🇨 constructor called" << std::endl;
}

C::~C(void)
{
	if (!SILENT)
		std::cout << ">> -🇨 destructor called" << std::endl;
}