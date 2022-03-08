/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/03/08 11:56:20 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

Bureaucrat::Bureaucrat(void) : _name("Mr Bureaucrat"), _grade(150)
{
	if (!SILENT)
		std::cout << ">> +💼 Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
	if (!SILENT)
		std::cout << ">> +💼 Bureaucrat param constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	if (!SILENT)
		std::cout << ">> +💼 Bureaucrat copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat(void)
{
	if (!SILENT)
		std::cout << ">> -💼 Bureaucrat destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::increaseGrade(void)
{
	if (!SILENT)
		std::cout << "🔼 Increase grade" << std::endl;
	if (this->getGrade() == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= 1;
}

void	Bureaucrat::decreaseGrade(void)
{
	if (!SILENT)
		std::cout << "🔽 Decrease grade" << std::endl;
	if (this->getGrade() == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += 1;
}

/*
** Operators overload
*/

// Assignment operator
Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (!SILENT)
		std::cout << ">> =💼 Bureaucrat assignment operator called" << std::endl;
	this->_name = rhs.getName();
	this->_grade = rhs.getGrade();
	return (*this);
}

// Insertion operator
std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return (o);
}

// Exceptions
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("❌ A bureaucrat grade cannot be that high !");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("❌ A bureaucrat grade cannot be that low !");
}
