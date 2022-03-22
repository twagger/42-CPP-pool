/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:07:29 by twagner           #+#    #+#             */
/*   Updated: 2022/03/22 11:25:52 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"
#include <cstdlib>
#include <limits>

// From converters

void	fromChar(t_type *data)
{
	data->i = static_cast<int>(data->c);
	data->f = static_cast<float>(data->c);
	data->d = static_cast<double>(data->c);
}

void	fromInt(t_type *data)
{
	if (!data->i_info.compare("Overflow") || !data->i_info.compare("Underflow"))
	{
		data->c_info = "Impossible (Int overflow / underflow)";
		data->f_info = "Impossible (Int overflow / underflow)";
		data->d_info = "Impossible (Int overflow / underflow)";
	}
	else
	{
		data->f = static_cast<float>(data->i);
		data->d = static_cast<double>(data->i);
		data->c = static_cast<int>(data->i);
		if (data->i > 127 || data->i < -127)
			data->c_info = "Impossible";
		else if (data->c < 32 || data->c > 126)
			data->c_info = "Non displayable";
	}
}

void	fromFloat(t_type *data)
{
	if (!data->f_info.compare("Overflow") || !data->f_info.compare("Underflow"))
	{
		data->c_info = "Impossible (Float overflow / underflow)";
		data->i_info = "Impossible (Float overflow / underflow)";
		data->d_info = "Impossible (Float overflow / underflow)";
	}
	else
	{
		data->d = static_cast<double>(data->f);
		data->i = static_cast<int>(data->f);
		if (data->f > std::numeric_limits<int>::max())
		{
			data->i_info = "Overflow";
		}
		else if (data->f < std::numeric_limits<int>::min())
		{
			data->i_info = "Underflow";
		}
		data->c = static_cast<char>(data->f);
		if (data->d > 127 || data->d < -127 || !data->c_info.compare("Impossible"))
			data->c_info = "Impossible";
		else if (data->c < 32 || data->c > 126)
			data->c_info = "Non displayable";
	}
}

void	fromDouble(t_type *data)
{
	if (!data->d_info.compare("Overflow") || !data->d_info.compare("Underflow"))
	{
		data->c_info = "Impossible (Double overflow / underflow)";
		data->i_info = "Impossible (Double overflow / underflow)";
		data->f_info = "Impossible (Double overflow / underflow)";
	}
	else
	{
		data->i = static_cast<int>(data->d);
		if (data->d > std::numeric_limits<int>::max())
		{
			data->i_info = "Overflow";
		}
		else if (data->d < std::numeric_limits<int>::min())
		{
			data->i_info = "Underflow";
		}
		data->f = static_cast<float>(data->d);
		if (data->d > std::numeric_limits<float>::max())
		{
			data->f_info = "Overflow";
		}
		else if (data->d < std::numeric_limits<float>::min())
		{
			data->f_info = "Underflow";
		}
		data->c = static_cast<char>(data->d);
		if (data->d > 127 || data->d < -127 || !data->c_info.compare("Impossible"))
			data->c_info = "Impossible";
		else if (data->c < 32 || data->c > 126)
			data->c_info = "Non displayable";
	}
}

// To converters

void	toChar(t_type *data)
{
	data->c = static_cast<char>(*(data->value));
	if (data->c < 32 || data->c > 126)
		data->c_info = "Non displayable";
}


void	toInt(t_type *data)
{
	long double	ld;
	
	ld = std::strtold(data->value, NULL);
	if (ld > std::numeric_limits<int>::max())
		data->i_info = "Overflow";
	else if (ld < std::numeric_limits<int>::min())
		data->i_info = "Underflow";
	else
		data->i = static_cast<int>(ld);
	std::cout << "i: " << data->i << std::endl;
}

void	toFloat(t_type *data)
{
	long double	ld;
	
	ld = std::strtold(data->value, NULL);
	if (ld > std::numeric_limits<float>::max())
		data->f_info = "Overflow";
	else if (ld < std::numeric_limits<float>::min())
		data->f_info = "Underflow";
	else
		data->f = static_cast<float>(ld);
}

void	toDouble(t_type *data)
{
	long double	ld;
	
	ld = std::strtold(data->value, NULL);
	if (ld > std::numeric_limits<double>::max())
		data->d_info = "Overflow";
	else if (ld < std::numeric_limits<double>::min())
		data->d_info = "Underflow";
	else
		data->d = static_cast<double>(ld);
}
