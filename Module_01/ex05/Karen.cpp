/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/02/12 11:09:09 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

/*
** Constructor and destructor
*/

Karen::Karen(void)
{
	std::cout << ">> + Karen constructor called" << std::endl;
}

Karen::~Karen(void)
{
	std::cout << ">> - Karen destructor called" << std::endl;
}

/*
** Member functions & accessors
*/
void	Karen::debug(void) const
{
	std::cout << "\033[1;33m[DEBUG]\033[0m "
			  << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !"
			  << std::endl;
}

void	Karen::info(void) const
{
	std::cout << "\033[1;36m[INFO]\033[0m "
			  << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !"
			  << std::endl;
}

void	Karen::warning(void) const
{
	std::cout << "\033[1;35m[WARNING]\033[0m "
			  << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
			  << std::endl;
}

void	Karen::error(void) const
{
	std::cout << "\033[1;31m[ERROR]\033[0m "
			  << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
			  << std::endl;	
}

void	Karen::complain(std::string level) const
{
	int			i;
	Comments	f[4] = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	i = -1;
	while (++i < 4)
	{
		if (levels[i].compare(level) == 0)
			(this->*(f[i]))();
	}
}
