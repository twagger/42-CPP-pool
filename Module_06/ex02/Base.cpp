/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:34:48 by twagner           #+#    #+#             */
/*   Updated: 2022/03/18 10:35:43 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

Base::Base(void)
{
	if (!SILENT)
		std::cout << ">> +💠 base constructor called" << std::endl;
}

Base::~Base(void)
{
	if (!SILENT)
		std::cout << ">> -💠 base destructor called" << std::endl;
}
