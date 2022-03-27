/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:27:48 by twagner           #+#    #+#             */
/*   Updated: 2022/03/27 11:30:58 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <exception>
#include <limits>
#include <cstdlib> 
#include <vector>
#include <algorithm>
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructors and destructor
*/

Span::Span(void) : _arr(NULL), _current_level(-1), _max_level(-1)
{
	if (!SILENT)	
		std::cout << ">> + Span default constructor called" << std::endl;
}

Span::Span(unsigned int N) : _current_level(-1), _max_level(N - 1)
{
	if (!SILENT)	
		std::cout << ">> + Span param constructor called" << std::endl;
	this->_arr = new int[N];
	std::fill(this->_arr, this->_arr + this->_max_level + 1, 0);
}

Span::Span(const Span &src) : _arr(NULL), _current_level(src.getCurrentLevel()), _max_level(src.getMaxLevel())
{
	if (!SILENT)	
		std::cout << ">> + Span copy constructor called" << std::endl;	
	*this = src;
}

Span::~Span()
{
	if (!SILENT)	
		std::cout << ">> - Span destructor called" << std::endl;
	delete [] this->_arr;
}

/*
** Operators overload
*/

Span	&Span::operator=(const Span &rhs)
{
	int	size;

	if (!SILENT)	
		std::cout << ">> = Span assignment operator called" << std::endl;
	if (this->_arr)
		delete [] this->_arr;
	size = rhs.getMaxLevel() + 1;
	this->_arr = new int[size];
	std::copy(rhs._arr, rhs._arr + size, this->_arr);
	return (*this);
}

/*
** Accessors
*/

int	Span::getMaxLevel(void) const
{
	return (this->_max_level);
}

int	Span::getCurrentLevel(void) const
{
	return (this->_current_level);
}

int	Span::getValue(int i) const
{
	if (i > this->_max_level)
		throw Span::OutOfRangeException();
	return (this->_arr[i]);
}

/*
** Member functions
*/

void	Span::addNumber(int number)
{
	if (this->_max_level < 0)
		throw Span::EmptySizeException();
	if (this->_current_level == this->_max_level)
		throw Span::FullSpanException();
	++this->_current_level;
	this->_arr[this->_current_level] = number;
}

void	Span::addNumber(std::vector<int>::iterator it, std::vector<int>::iterator ite)
{
	if (this->_max_level < 0)
		throw Span::EmptySizeException();
	if (this->_current_level == this->_max_level)
		throw Span::FullSpanException();
	try
	{
		while (it < ite)
		{
			this->addNumber(*it);
			++it;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int Span::shortestSpan(void) const
{
	int	span = std::numeric_limits<int>::max();	
	int	*it = this->_arr;
	int	*ite = this->_arr + this->_current_level + 1;

	if (this->getCurrentLevel() < 0)
		throw Span::EmptySizeException();
	if (this->getCurrentLevel() == 0)
		throw Span::OneElementException();
	std::sort(it, ite);
	if (std::adjacent_find(it, ite) != ite)
		return (0);
	while (it < ite)
	{
		if ((it + 1 != ite) && abs(*it - *(it + 1)) < span)
			span = abs(*it - *(it + 1));
		++it;
	}
	return (span);
}

int	Span::longestSpan(void) const
{
	int	*it = this->_arr;
	int	*ite = this->_arr + this->_current_level + 1;

	if (this->getCurrentLevel() < 0)
		throw Span::EmptySizeException();
	if (this->getCurrentLevel() == 0)
		throw Span::OneElementException();
	return (*std::max_element(it, ite) - *std::min_element(it, ite));
}

/*
** Exceptions
*/

const char	*Span::FullSpanException::what() const throw()
{
	return ("❌ The span is full");
}

const char	*Span::OneElementException::what() const throw()
{
	return ("❌ There is only one element in the span");
}

const char	*Span::EmptySizeException::what() const throw()
{
	return ("❌ The span size is null");
}

const char	*Span::OutOfRangeException::what() const throw()
{
	return ("❌ The index is out of range");
}
