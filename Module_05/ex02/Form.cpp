/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
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

AForm::AForm(void) 
: _name("My AForm"), _isSigned(false), _gradeToSign(150),  _gradeToExecute(150)
{
	if (!SILENT)
		std::cout << ">> +📝 AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute) 
: _name(name), _isSigned(false),
_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (!SILENT)
		std::cout << ">> +📝 AForm param constructor called" << std::endl;
	if (gradeToSign < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150)
		throw AForm::GradeTooLowException();
	else if (gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &src)
: _name(src.getName()), 
 _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
	if (!SILENT)
		std::cout << ">> +📝 AForm copy constructor called" << std::endl;
	*this = src;
}

AForm::~AForm(void)
{
	if (!SILENT)
		std::cout << ">> -📝 AForm destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSignedStatus(void) const
{
	return (this->_isSigned);
}

unsigned int	AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

unsigned int	AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void	AForm::beSigned(Bureaucrat const *bur)
{
	if (bur->getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	else
		this->_isSigned = true;
}

/*
** Operators overload
*/

// Assignment operator
AForm	&AForm::operator=(AForm const &rhs)
{
	if (!SILENT)
		std::cout << ">> =📝 AForm assignment operator called" << std::endl;
	this->_isSigned = rhs.getSignedStatus();
	return (*this);
}

// Insertion operator
std::ostream	&operator<<(std::ostream &o, AForm const &i)
{
	o << "-----------------------------" << std::endl
	  << "AForm             : " << i.getName() << std::endl
	  << "Signed           : " << i.getSignedStatus() << std::endl
	  << "Grade to sign    : " << i.getGradeToSign() << std::endl
	  << "Grade to execute : " << i.getGradeToExecute() << std::endl
	  << "-----------------------------" << std::endl;
	return (o);
}

// Exceptions
const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("❌ The grade is too high !");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("❌ The grade is too low !");
}
