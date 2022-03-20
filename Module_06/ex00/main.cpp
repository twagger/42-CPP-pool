/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:06:18 by twagner           #+#    #+#             */
/*   Updated: 2022/03/20 12:08:21 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (*(s + i))
		++i;
	return (i);
}

int	ft_strchr_index(const char *s, int c, int offset)
{
	int	i;

	if (offset == -1)
	{
		i = ft_strlen(s);
		while (--i >= 0)
			if (s[i] == (char)c)
				return (i);
	}
	else
	{
		i = -1;
		while (s[++i + offset])
		{
			if (s[i + offset] == (char)c)
				return (i + offset);
		}
		if (c == 0 && s)
			return (i + offset);
	}
	return (-1);
}

bool	isNumber(char *str)
{
	int			i;
	int			f_count;
	int			dot_count;
	int			num_count;
	std::string	valid = "0123456789.f";

	i = 0;
	f_count = 0;
	dot_count = 0;
	num_count = 0;
	if (str[i] == '+' || str[i] == '-')
		++i;
	if (!str[i])
		return (false);
	while (str[i] && valid.find(str[i]) != std::string::npos)
	{
		switch (str[i])
		{
			case '.':
				if (dot_count != 0)
					return (false);
				++dot_count;
				break;
			case 'f':
				if (f_count || str[i + 1] != 0)
					return (false);
				++f_count;
				break;
			default:
				++num_count;		
				break;
		}
		++i;
	}
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		return(false);
	if (num_count == 0)
		return (false);
	return (true);
}

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
	data->value = static_cast<void *>(str);
}

void	display(t_type *data)
{
	std::string	types[5] = {"CHAR", "INT", "FLOAT", "DOUBLE", "ERROR"};

	std::cout << std::endl;
	std::cout << "\033[1;35m---[ Conversions ]---\033[0m" << std::endl;

	// TRUE TYPE
	std::cout << "True type : " << types[data->true_type] << std::endl;
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
		std::cout << "float: " << data->f << "f" << std::endl;
	// DOUBLE
	if (!data->d_info.empty())
		std::cout << "double: " << data->d_info << std::endl;
	else
		std::cout << "double: " << data->d << std::endl;
}

void	convert(t_type *data)
{
	long int	li;

	// switch case on true_type
	// int > fromInt
	// char > fromChar
	// float > fromFloat
	// double > fromDouble
	// faire les petites fonctions ci dessus
	// faire des petites fonctions toInt, toChar, toFloat, toDouble
	// INT Convertion
	li = std::strtol(static_cast<char *>(data->value), NULL, 10);
	if (li > std::numeric_limits<int>::max())
		data->i_info = "overflow";
	else if (li < std::numeric_limits<int>::min())
		data->i_info = "underflow";
	else
	{
		data->i_info.clear();
		data->i = static_cast<int>(li);
	}
}

void	detect_type(t_type *data)
{
	long double	ld;
	char		*str;

	str = static_cast<char *>(data->value);
	// check if it is an int, float or double
	if (isNumber(str) == true)
	{
		ld = std::strtold(str, NULL);
		if (ft_strchr_index(str, 'f', 0) != -1)
		{
			data->true_type = TT_FLOAT;
			if (ld > std::numeric_limits<float>::max())
				data->f_info = "overflow";
			else if (ld < std::numeric_limits<float>::min())
				data->f_info = "underflow";
			else
				data->f = static_cast<float>(ld);
		}
		else if (ft_strchr_index(str, '.', 0) != -1)
		{
			data->true_type = TT_DOUBLE;
			if (ld > std::numeric_limits<double>::max())
				data->d_info = "overflow";
			else if (ld < std::numeric_limits<double>::min())
				data->d_info = "underflow";
			else
				data->d = static_cast<double>(ld);
		}
		else
		{
			data->true_type = TT_INT;
			if (ld > std::numeric_limits<int>::max())
				data->i_info = "overflow";
			else if (ld < std::numeric_limits<int>::min())
				data->i_info = "underflow";
			else
				data->i = static_cast<int>(ld);
		}
	}
	// check if it is a char
	else if (str[0] && !str[1] && str[0] >= 32 && str[0] < 127)
	{
		data->true_type = TT_CHAR;
		data->c = static_cast<char>(str[0]);
	}
}

int main(int ac, char **av)
{
	t_type	data;

	// param check
	if (ac != 2)
	{
		std::cerr << "Error : wrong number of arguments" << std::endl;
		return (1);
	}

	// data init
	init(av[1], &data);
	// detect true type
	detect_type(&data);
	// convert
	convert(&data);
	// display conversions
	display(&data);

	// END OF MAIN
	std::cout << std::endl;
	std::cout << "\033[1;35m >>> End of main <<<\033[0m" << std::endl;
	return (0);
}
