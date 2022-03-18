/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:31:18 by twagner           #+#    #+#             */
/*   Updated: 2022/03/18 10:33:23 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"
#include <iostream>
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

B::B(void)
{
	if (!SILENT)
		std::cout << ">> +🇧 constructor called" << std::endl;
}

B::~B(void)
{
	if (!SILENT)
		std::cout << ">> -🇧 destructor called" << std::endl;
}
