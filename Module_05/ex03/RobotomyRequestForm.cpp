/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/03/11 11:10:23 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <fstream>
#include <stdlib.h>
#include <ctime>
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

RobotomyRequestForm::RobotomyRequestForm(void) 
: AForm("Default Robotomy form", 72, 45), _target("Default Target")
{
	if (!SILENT)
		std::cout << ">> +🤖 RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
: AForm("Robotomy form", 72, 45), _target(target)
{
	if (!SILENT)
		std::cout << ">> +🤖 RobotomyRequestForm param constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
: AForm(src.getName(), 145, 137)
{
	if (!SILENT)
		std::cout << ">> +🤖 RobotomyRequestForm copy constructor called" << std::endl;
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	if (!SILENT)
		std::cout << ">> -🤖 RobotomyRequestForm destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{

	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (this->getSignedStatus() == false)
		throw AForm::UnsignedFormException();
	else
	{
		std::cout << ">> 🔩 **Drill sound** " << std::endl;
		std::srand(std::time(NULL));
		if (std::rand() % 2)
		{
			std::cout << "✅ " << this->getTarget() << " has been robotomized with success !" << std::endl;
		}
		else
			std::cout << "❌ robotomization failed for " << this->getTarget() << "." << std::endl;
	}
}

/*
** Operators overload
*/

// Assignment operator
RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (!SILENT)
		std::cout << ">> =🤖 RobotomyRequestForm assignment operator called" << std::endl;
	this->_target = rhs.getTarget();
	return (*this);
}
