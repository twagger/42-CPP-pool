/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:50:52 by twagner           #+#    #+#             */
/*   Updated: 2022/03/19 15:49:30 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif
#include "Array.hpp"
#include <iostream>
#include <stdexcept>


// Constructors and destructor
template< typename T >
Array<T>::Array(void)
{
	if (!SILENT)
		std::cout << ">> +🗃️ Array default constructor called" << std::endl;
	this->_array = new T[0];
	this->_size = 0;
	this->_isAllocated = true;
}

template< typename T >
Array<T>::Array(unsigned int n)
{
	T	*tmp;

	if (!SILENT)
		std::cout << ">> +🗃️ Array param constructor called" << std::endl;
	this->_array = new T[n];
	this->_size = n;
	this->_isAllocated = true;
	for (unsigned int i = 0; i < n; i++)
	{
		tmp = new T();
		this->_array[i] = *tmp;
		delete tmp;	
	}
}

template< typename T >
Array<T>::Array(Array const &src)
{
	if (!SILENT)
		std::cout << ">> +🗃️ Array copy constructor called" << std::endl;
	this->_isAllocated = false;
	*this = src;
}

template< typename T >
Array<T>::~Array(void)
{
	if (!SILENT)
		std::cout << ">> -🗃️ Array destructor called" << std::endl;
	delete [] this->_array;
}

// Accessors
template< typename T >
unsigned int	Array<T>::getSize(void) const
{
	return (this->_size);
}

template< typename T >
T	&Array<T>::getItem(unsigned int i) const
{
	return (this->_array[i]);
}

// Assignment operator
template< typename T >
Array<T>	&Array<T>::operator=(Array<T> const &rhs)
{	
	if (!SILENT)
		std::cout << ">> =🗃️ Array assignment operator called" << std::endl;
	if (this->_isAllocated == true)
	{
		delete [] this->_array;
	}	
	this->_array = new T[rhs.getSize()];
	this->_isAllocated = true;
	for (unsigned int i = 0; i < rhs.getSize(); i++)
	{
		this->_array[i] = rhs.getItem(i);
	}
	return (*this);
}

template< typename T >
T	&Array<T>::operator[](unsigned int i)
{
	if (!SILENT)
		std::cout << ">> =🗃️ Array index operator called" << std::endl;
	if (i >= this->_size)
	{
		throw std::out_of_range("Out of range");
	}
	else
	{
		return (this->_array[i]);
	}
}
