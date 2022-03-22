/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:06:18 by twagner           #+#    #+#             */
/*   Updated: 2022/03/22 11:24:23 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

void	init(char *str, t_type *data)
{
	data->c = 0;
	data->i = 0;
	data->f = 0.0f;
	data->d = 0.0;
	data->c_info.clear();
	data->i_info.clear();
	data->f_info.clear();
	data->d_info.clear();
	data->true_type = TT_ERROR;
	data->value = str;
}

void	display(t_type *data)
{
	std::string	types[5] = {"CHAR", "INT", "FLOAT", "DOUBLE", "ERROR"};

	std::cout << std::endl;
	std::cout << "\033[1;35m---[ Conversions ]---\033[0m" << std::endl;
	std::cout << "True type : " << types[data->true_type] << std::endl << std::endl;
	// CHAR
	if (!data->c_info.empty())
		std::cout << "char: " << data->c_info << std::endl;
	else
		std::cout << "char: " << data->c << std::endl;
	// INT
	if (!data->i_info.empty())
		std::cout << "int: " << data->i_info << std::endl;
	else
		std::cout << "int: " << data->i << std::endl;
	// FLOAT
	if (!data->f_info.empty())
		std::cout << "float: " << data->f_info << std::endl;
	else
		std::cout << "float: " << std::setprecision(1) << std::fixed << data->f << "f" << std::endl;
	// DOUBLE
	if (!data->d_info.empty())
		std::cout << "double: " << data->d_info << std::endl;
	else
		std::cout << "double: " << std::setprecision(1) << std::fixed << data->d << std::endl;
	std::cout << "\033[1;35m---------------------\033[0m" << std::endl << std::endl;
}

void	convert(t_type *data)
{
	switch (data->true_type)
	{
		case TT_CHAR:
			fromChar(data);
			break;
		case TT_INT:
			fromInt(data);
			break;
		case TT_FLOAT:
			fromFloat(data);
			break;
		case TT_DOUBLE:
			fromDouble(data);
			break;
		default:
			data->c_info = "Impossible";
			data->i_info = "Impossible";
			data->f_info = "Impossible";
			data->d_info = "Impossible";
			break;
	}
}

bool	handle_pseudo_litteral(t_type *data)
{
	std::string	tmp;

	tmp = static_cast<std::string>(data->value);
	if (!tmp.compare("-inff") || !tmp.compare("+inff") || !tmp.compare("nanf"))
	{
		data->true_type = TT_FLOAT;
		data->c_info = "Impossible";
		data->i_info = "Impossible";
		toFloat(data);
	}
	if (!tmp.compare("-inf") || !tmp.compare("+inf") || !tmp.compare("nan"))
	{
		data->true_type = TT_DOUBLE;
		data->c_info = "Impossible";
		data->i_info = "Impossible";
		toDouble(data);
	}
	return (false);
}

void	detect_type(t_type *data)
{
	char	*str;

	str = data->value;
	if (handle_pseudo_litteral(data))
		return;
	else if (isNumber(str) == true)
	{
		if (ft_strchr_index(str, 'f', 0) != -1)
		{
			data->true_type = TT_FLOAT;
			toFloat(data);
		}
		else if (ft_strchr_index(str, '.', 0) != -1)
		{
			data->true_type = TT_DOUBLE;
			toDouble(data);
		}
		else
		{
			data->true_type = TT_INT;
			toInt(data);
		}
	}
	else if (str[0] && !str[1] && str[0] >= 32 && str[0] < 127)
	{
		data->true_type = TT_CHAR;
		toChar(data);
	}
}

int main(int ac, char **av)
{
	t_type	data;

	if (ac != 2)
	{
		std::cerr << "Error : wrong number of arguments" << std::endl;
		return (1);
	}
	init(av[1], &data);
	detect_type(&data);
	convert(&data);
	display(&data);
	return (0);
}
