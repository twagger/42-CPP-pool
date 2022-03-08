/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/03/08 13:23:58 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

Form::Form(void) 
: _name("My Form"), _isSigned(false), _gradeToSign(150),  _gradeToExecute(150)
{
	if (!SILENT)
		std::cout << ">> +📝 Form default constructor called" << std::endl;
}

Form::Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute) 
: _name(name), _isSigned(false),
_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (!SILENT)
		std::cout << ">> +📝 Form param constructor called" << std::endl;
	if (gradeToSign < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150)
		throw Form::GradeTooLowException();
	else if (gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &src)
: _name(src.getName()), 
 _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
	if (!SILENT)
		std::cout << ">> +📝 Form copy constructor called" << std::endl;
	*this = src;
}

Form::~Form(void)
{
	if (!SILENT)
		std::cout << ">> -📝 Form destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSignedStatus(void) const
{
	return (this->_isSigned);
}

unsigned int	Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

unsigned int	Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void	Form::beSigned(Bureaucrat const *bur)
{
	if (bur->getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	else
		this->_isSigned = true;
}

/*
** Operators overload
*/

// Assignment operator
Form	&Form::operator=(Form const &rhs)
{
	if (!SILENT)
		std::cout << ">> =📝 Form assignment operator called" << std::endl;
	this->_isSigned = rhs.getSignedStatus();
	return (*this);
}

// Insertion operator
std::ostream	&operator<<(std::ostream &o, Form const &i)
{
	o << "-----------------------------" << std::endl
	  << "Form             : " << i.getName() << std::endl
	  << "Signed           : " << i.getSignedStatus() << std::endl
	  << "Grade to sign    : " << i.getGradeToSign() << std::endl
	  << "Grade to execute : " << i.getGradeToExecute() << std::endl
	  << "-----------------------------" << std::endl;
	return (o);
}

// Exceptions
const char	*Form::GradeTooHighException::what() const throw()
{
	return ("❌ The grade is too high !");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("❌ The grade is too low !");
}
