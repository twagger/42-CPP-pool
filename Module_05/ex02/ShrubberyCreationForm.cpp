/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/03/08 17:34:34 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
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

ShrubberyCreationForm::ShrubberyCreationForm(void) 
: AForm("Default Shrubbery form", 145, 137), _target("Default Target")
{
	if (!SILENT)
		std::cout << ">> +🌳 ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
: AForm("Shrubbery form", 145, 137), _target(target)
{
	if (!SILENT)
		std::cout << ">> +🌳 ShrubberyCreationForm param constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
: AForm(src.getName(), 145, 137)
{
	if (!SILENT)
		std::cout << ">> +🌳 ShrubberyCreationForm copy constructor called" << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (!SILENT)
		std::cout << ">> -🌳 ShrubberyCreationForm destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
	{
		std::ofstream	ofile(this->getTarget().append("_shrubbery"));
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
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (!SILENT)
		std::cout << ">> =🌳 ShrubberyCreationForm assignment operator called" << std::endl;
	this->_target = rhs.getTarget();
	return (*this);
}
