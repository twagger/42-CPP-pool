/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:11:40 by twagner           #+#    #+#             */
/*   Updated: 2022/02/12 11:01:57 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(int ac, char **av)
{
	std::string	level;
	Karen 		karen;

	if (ac != 2)
	{
		std::cerr << "ERROR : wrong number of arguments" << std::endl;
		return (1);
	}
	level = av[1];
	karen.complain(level);
	return (0);
}
