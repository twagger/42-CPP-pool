/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/03/11 09:54:18 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <fstream>
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

PresidentialPardonForm::PresidentialPardonForm(void) 
: AForm("Default Presidential Pardon form", 25, 5), _target("Default target")
{
	if (!SILENT)
		std::cout << ">> +🏰 PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
: AForm("Presidential Pardon form", 25, 5), _target(target)
{
	if (!SILENT)
		std::cout << ">> +🏰 PresidentialPardonForm param constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
: AForm(src.getName(), 25, 5)
{
	if (!SILENT)
		std::cout << ">> +🏰 PresidentialPardonForm copy constructor called" << std::endl;
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	if (!SILENT)
		std::cout << ">> -🏰 PresidentialPardonForm destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (this->getSignedStatus() == false)
		throw AForm::UnsignedFormException();
	else
	{
		std::cout << "✋ " << this->getTarget() << " has been forgiven by Zaphod Beeblebrox." << std::endl;
	}
}

/*
** Operators overload
*/

// Assignment operator
PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (!SILENT)
		std::cout << ">> =🏰 PresidentialPardonForm assignment operator called" << std::endl;
	this->_target = rhs.getTarget();
	return (*this);
}
