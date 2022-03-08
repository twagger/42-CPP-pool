/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/03/08 16:49:11 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <fstream>
#include <stdlib.h>
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

RobotomyRequestForm::RobotomyRequestForm(void) 
: AForm("Default Robotomy form", 72, 45)
{
	if (!SILENT)
		std::cout << ">> +🤖 RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name) 
: AForm(name, 72, 45)
{
	if (!SILENT)
		std::cout << ">> +🤖 RobotomyRequestForm param constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
: AForm(src.getName(), 145, 137)
{
	if (!SILENT)
		std::cout << ">> +🤖 RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	if (!SILENT)
		std::cout << ">> -🤖 RobotomyRequestForm destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

void	RobotomyRequestForm::execute(Bureaucrat const *bur, std::string &target) const
{
	if (bur->getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << ">> 🔩 **Drill sound** " << std::endl;
		if ((rand() % 2) + 1 == 2)
		{
			std::cout << "✅ " << target << " has been robotomized with success !" << std::endl;
		}
		else
			std::cout << "❌ robotomization failed for " << target << "." << std::endl;
	}
}

/*
** Operators overload
*/

// Assignment operator
RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &)
{
	if (!SILENT)
		std::cout << ">> =🤖 RobotomyRequestForm assignment operator called" << std::endl;
	return (*this);
}
