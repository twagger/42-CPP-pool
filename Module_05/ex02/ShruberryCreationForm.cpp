/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/03/08 17:18:47 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShruberryCreationForm.hpp"
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

ShruberryCreationForm::ShruberryCreationForm(void) 
: AForm("Default Shruberry form", 145, 137), _target("Default Target")
{
	if (!SILENT)
		std::cout << ">> +🌳 ShruberryCreationForm default constructor called" << std::endl;
}

ShruberryCreationForm::ShruberryCreationForm(std::string target) 
: AForm("Shruberry form", 145, 137), _target(target)
{
	if (!SILENT)
		std::cout << ">> +🌳 ShruberryCreationForm param constructor called" << std::endl;
}

ShruberryCreationForm::ShruberryCreationForm(ShruberryCreationForm const &src)
: AForm(src.getName(), 145, 137)
{
	if (!SILENT)
		std::cout << ">> +🌳 ShruberryCreationForm copy constructor called" << std::endl;
	*this = src;
}

ShruberryCreationForm::~ShruberryCreationForm(void)
{
	if (!SILENT)
		std::cout << ">> -🌳 ShruberryCreationForm destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

std::string	ShruberryCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShruberryCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
	{
		std::ofstream	ofile(this->getTarget().append("_shruberry"));
		for (int i = 0; i < 10; i++)
		{
		    ofile << "       ###" << std::endl
				  << "      #o###" << std::endl
				  << "    #####o###" << std::endl
				  << "   #o#\\#|#/###" << std::endl
				  << "    ###\\|/#o#" << std::endl
				  << "     # }|{  #" << std::endl
				  << "       }|{" << std::endl << std::endl;
		}
		ofile.close();
	}
}

/*
** Operators overload
*/

// Assignment operator
ShruberryCreationForm	&ShruberryCreationForm::operator=(ShruberryCreationForm const &rhs)
{
	if (!SILENT)
		std::cout << ">> =🌳 ShruberryCreationForm assignment operator called" << std::endl;
	this->_target = rhs.getTarget();
	return (*this);
}
