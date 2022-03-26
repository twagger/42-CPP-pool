/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:27:48 by twagner           #+#    #+#             */
/*   Updated: 2022/03/26 14:33:20 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <exception>
#include <limits>
#include <cstdlib> 
#include <vector>
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
	for (unsigned int i = 0; i < N; ++i)
	{
		this->_arr[i] = 0;
	}
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
	for (int i = 0; i < size; ++i)
	{
		this->_arr[i] = rhs.getValue(i);
	}
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
		throw std::out_of_range("The index is out of range");
	return (this->_arr[i]);
}

/*
** Member functions
*/

void	Span::addNumber(int number)
{
	if (this->_max_level < 0)
		throw std::runtime_error("Table cannot contain any item");
	if (this->_current_level == this->_max_level)
		throw std::runtime_error("Table is full");
	++this->_current_level;
	this->_arr[this->_current_level] = number;
}

void	Span::addNumber(std::vector<int>::iterator it, std::vector<int>::iterator ite)
{
	if (this->_max_level < 0)
		throw std::runtime_error("Table cannot contain any item");
	if (this->_current_level == this->_max_level)
		throw std::runtime_error("Table is full");
	for (int i = this->_current_level + 1; i < this->_max_level + 1; ++i)
	{
		if (it != ite)
		{
			this->_arr[i] = *it;
			++this->_current_level;
			++it;
		}
	}
}

int Span::shortestSpan(void) const
{
	int span;

	span = std::numeric_limits<int>::max();
	if (this->getCurrentLevel() <= 0)
		throw std::runtime_error("Table is empty or contains only one element");
	for (int i = 0; i < this->_current_level + 1; ++i)
	{
		for (int j = 0; j < this->_current_level + 1; ++j)
		{
			if (i != j)
			{
				if (abs(this->_arr[i] - this->_arr[j]) < span)
					span = abs(this->_arr[i] - this->_arr[j]);
			}
		}
	}
	return (span);
}

int	Span::longestSpan(void) const
{
	int	min;
	int	max;

	if (this->getCurrentLevel() <= 0)
		throw std::runtime_error("Table is empty or contains only one element");
	min = this->_arr[0];
	max = this->_arr[0];
	for (int i = 0; i < this->_current_level + 1; ++i)
	{
		if (this->_arr[i] < min)
			min = this->_arr[i];
		if (this->_arr[i] > max)
			max = this->_arr[i];
	}
	return (max - min);
}
