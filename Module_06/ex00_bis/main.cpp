/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:06:18 by twagner           #+#    #+#             */
/*   Updated: 2022/03/19 16:47:00 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>

void	convert(char *str, char *c, int *i, float *f, double *d)
{
	if (str[0] && !str[1])
	{
		*c = static_cast<char>(str[0]);
		*i = static_cast<int>(str[0]);
		*f = static_cast<float>(str[0]);
		*d = static_cast<double>(str[0]);
	}
	else
	{
		*c = static_cast<char>(std::atoi(str));
		*i = static_cast<int>(std::atoi(str));
		*f = static_cast<float>(std::atof(str));
		*d = static_cast<double>(std::atof(str));
	}
}

void	display(char c, int i, float f, double d)
{
	std::cout << std::endl;
	std::cout << "\033[1;35m---[ Conversions ]---\033[0m" << std::endl;
	if (c < 32 || c >= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::setprecision(1) << std::fixed << f << "f" << std::endl;
	std::cout << "double: " << std::setprecision(1) << std::fixed << d << std::endl;
}

int main(int ac, char **av)
{
	char	c;
	int		i;
	float	f;
	double	d;

	// param check
	if (ac != 2)
	{
		std::cerr << "Error : wrong number of arguments" << std::endl;
		return (1);
	}

	// detect type


	// convert
	convert(av[1], &c, &i, &f, &d);

	// display conversions
	display(c, i, f, d);

	// END OF MAIN
	std::cout << std::endl;
	std::cout << "\033[1;35m >>> End of main <<<\033[0m" << std::endl;
	return (0);
}