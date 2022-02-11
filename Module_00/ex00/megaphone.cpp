/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@studen.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:57:08 by twagner           #+#    #+#             */
/*   Updated: 2022/02/05 10:57:08 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	int		i;

	if (ac != 1)
	{
		++av;
		while (*av)
		{
			i = -1;
			while ((*av)[++i])
				(*av)[i] = std::toupper((*av)[i]);
			std::cout << *av;
			++av;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
