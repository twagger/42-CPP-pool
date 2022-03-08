/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/03/08 16:34:42 by twagner          ###   ########.fr       */
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
: AForm("Default Shruberry form", 145, 137)
{
	if (!SILENT)
		std::cout << ">> +🌳 ShruberryCreationForm default constructor called" << std::endl;
}

ShruberryCreationForm::ShruberryCreationForm(std::string name) 
: AForm(name, 145, 137)
{
	if (!SILENT)
		std::cout << ">> +🌳 ShruberryCreationForm param constructor called" << std::endl;
}

ShruberryCreationForm::ShruberryCreationForm(ShruberryCreationForm const &src)
: AForm(src.getName(), 145, 137)
{
	if (!SILENT)
		std::cout << ">> +🌳 ShruberryCreationForm copy constructor called" << std::endl;
}

ShruberryCreationForm::~ShruberryCreationForm(void)
{
	if (!SILENT)
		std::cout << ">> -🌳 ShruberryCreationForm destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

void	ShruberryCreationForm::execute(Bureaucrat const *bur, std::string &target, unsigned int nbTree) const
{
	if (bur->getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
	{
		std::ofstream	ofile(target.append("_shruberry"));
		for (int i = 0; i < nbTree; i++)
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
ShruberryCreationForm	&ShruberryCreationForm::operator=(ShruberryCreationForm const &)
{
	if (!SILENT)
		std::cout << ">> =🌳 ShruberryCreationForm assignment operator called" << std::endl;
	return (*this);
}
