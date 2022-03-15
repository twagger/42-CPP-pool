/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Litteral.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:13:33 by twagner           #+#    #+#             */
/*   Updated: 2022/03/15 15:44:14 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Litteral.hpp"
#include <cstdlib>
#include <bits/stdc++.h>
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

Litteral::Litteral(void) : _litteral(NULL)
{
	if (!SILENT)
		std::cout << ">> +⭕ Litteral default constructor called" << std::endl;
}

Litteral::Litteral(char	*litteral) : _litteral(litteral)
{
	if (!SILENT)
		std::cout << ">> +⭕ Litteral param constructor called" << std::endl;

}

Litteral::Litteral(Litteral const &src)
{
	if (!SILENT)
		std::cout << ">> +⭕ Litteral copy constructor called" << std::endl;
	*this = src;
}

Litteral::~Litteral(void)
{
	if (!SILENT)
		std::cout << ">> -⭕ Litteral destructor called" << std::endl;
}

/*
** Member functions & accessors
*/
char	*Litteral::getLitteral(void) const
{
	return (this->_litteral);
}

bool	Litteral::isNumber(void) const
{
	int			i;
	int			f_count;
	int			dot_count;
	std::string	valid = "0123456789.f";

	i = 0;
	f_count = 0;
	dot_count = 0;
	if (this->_litteral[i] == '+' || this->_litteral[i] == '-')
		++i;
	while (this->_litteral[i] && valid.find(this->_litteral[i]) != std::string::npos)
	{
		switch (this->_litteral[i])
		{
			case '.':
				if (dot_count != 0)
					return (false);
				++dot_count;
				break;
			case 'f':
				if (f_count || this->_litteral[i + 1] != 0)
					return (false);
				++f_count;
				break;
			default:
				break;
		}
		++i;
	}
	if (this->_litteral[i])
		return(false);
	return (true);
}

bool	Litteral::isNonNumeric(void) const
{
	if (this->_litteral[0] > 32 && this->_litteral[0] < 127)
	{
		if (this->_litteral[0] >= '0' && this->_litteral[0] <= '9')
			return (false);
		else
			return (true);
	}
	return (false);
}

char	Litteral::toChar(void) const
{
	if (this->_litteral[1])
	{
		if (this->isNumber() == false)
		{
			throw Litteral::ImpossibleConversionException();
			return (0);
		}
	}
	else if (this->isNonNumeric() == true)
	{
		return (this->_litteral[0]);
	}
	if (std::atoi(this->_litteral) < 32 || std::atoi(this->_litteral) > 126)
	{
		if (std::atoi(this->_litteral) > 255)
			throw Litteral::ImpossibleConversionException();
		else
			throw Litteral::NonDisplayableException();
		return (0);
	}
	return (static_cast<char>(std::atoi(this->_litteral)));
}

int	Litteral::toInt(void) const
{
	long	tmp;

	tmp = static_cast<long>(std::atol(this->_litteral));
	if (tmp > INT_MAX)
	{
		throw Litteral::OverflowException();
		return (0);
	}
	else if (tmp < INT_MIN)
	{
		throw Litteral::UnderflowException();
		return (0);
	}
	else
	{
		if (this->isNumber() == false)
		{
			throw Litteral::ImpossibleConversionException();
			return (0);
		}
	}
	return (static_cast<int>(std::atoi(this->_litteral)));
	
}

float	Litteral::toFloat(void) const
{
	std::string	temp;

	temp = static_cast<std::string>(this->_litteral);
	if (this->isNumber() == false)
	{
		if (temp.compare("nan") && temp.compare("nanf")
			&& temp.compare("+inf") && temp.compare("+inff")
			&& temp.compare("-inf") && temp.compare("-inff"))
		{
			throw Litteral::ImpossibleConversionException();
			return (0);
		}
	}
	return (static_cast<float>(std::atof(this->_litteral)));
}

double	Litteral::toDouble(void) const
{
	std::string	temp;

	temp = static_cast<std::string>(this->_litteral);
	if (this->isNumber() == false)
	{
		if (temp.compare("nan") && temp.compare("nanf")
			&& temp.compare("+inf") && temp.compare("+inff")
			&& temp.compare("-inf") && temp.compare("-inff"))
		{
			throw Litteral::ImpossibleConversionException();
			return (0);
		}
	}
	return (static_cast<double>(std::atof(this->_litteral)));
}

/*
** Operators overload
*/

// Assignment operator
Litteral	&Litteral::operator=(Litteral const &rhs)
{
	if (!SILENT)
		std::cout << ">> =⭕ Litteral assignment operator called" << std::endl;
	this->_litteral = rhs.getLitteral();
	return (*this);
}

/*
** Exceptions
*/

const char	*Litteral::ImpossibleConversionException::what() const throw()
{
	return ("impossible");
}

const char	*Litteral::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
}

const char	*Litteral::OverflowException::what() const throw()
{
	return ("overflow");
}

const char	*Litteral::UnderflowException::what() const throw()
{
	return ("underflow");
}
