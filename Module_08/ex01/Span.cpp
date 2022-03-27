/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:27:48 by twagner           #+#    #+#             */
/*   Updated: 2022/03/27 15:58:34 by twagner          ###   ########.fr       */
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

Span::Span(void) : _max(0)
{
	if (!SILENT)	
		std::cout << ">> + Span default constructor called" << std::endl;
}

Span::Span(unsigned int N) : _max(N)
{
	if (!SILENT)	
		std::cout << ">> + Span param constructor called" << std::endl;
	this->_arr.reserve(N);
}

Span::Span(const Span &src) : _max(src._max)
{
	if (!SILENT)	
		std::cout << ">> + Span copy constructor called" << std::endl;	
	*this = src;
}

Span::~Span()
{
	if (!SILENT)	
		std::cout << ">> - Span destructor called" << std::endl;
	this->_arr.clear();
}

/*
** Operators overload
*/

Span	&Span::operator=(const Span &rhs)
{
	if (!SILENT)	
		std::cout << ">> = Span assignment operator called" << std::endl;
	this->_arr.reserve(rhs._arr.capacity());
	this->_arr.assign(rhs._arr.begin(), rhs._arr.end());
	return (*this);
}

/*
** Accessors
*/

int	Span::getValue(unsigned int i) const
{
	if (i >= this->_arr.capacity())
		throw Span::OutOfRangeException();
	return (this->_arr.at(i));
}

/*
** Member functions
*/

void	Span::addNumber(int number)
{
	if (this->_max == 0)
		throw Span::EmptySizeException();
	if (this->_arr.size() == this->_max)
		throw Span::FullSpanException();
	this->_arr.push_back(number);
}

void	Span::addNumber(std::vector<int>::iterator it, std::vector<int>::iterator ite)
{
	if (this->_max == 0)
		throw Span::EmptySizeException();
	if (this->_arr.size() == this->_max)
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

int Span::shortestSpan(void)
{
	int	span = std::numeric_limits<int>::max();	
	std::vector<int>::iterator	it = this->_arr.begin();
	std::vector<int>::iterator	ite = this->_arr.end();

	if (this->_max == 0)
		throw Span::EmptySizeException();
	if (this->_arr.size() == 1)
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
	std::vector<int>::const_iterator	it = this->_arr.begin();
	std::vector<int>::const_iterator	ite = this->_arr.end();

	if (this->_max == 0)
		throw Span::EmptySizeException();
	if (this->_arr.size() == 1)
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
