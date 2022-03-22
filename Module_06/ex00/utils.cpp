/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:57:28 by twagner           #+#    #+#             */
/*   Updated: 2022/03/22 09:59:51 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"
#include <iostream>

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

