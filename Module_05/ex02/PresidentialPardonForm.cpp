/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/03/08 16:54:23 by twagner          ###   ########.fr       */
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
: AForm("Default Shruberry form", 25, 5)
{
	if (!SILENT)
		std::cout << ">> +🤴🏾 PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) 
: AForm(name, 25, 5)
{
	if (!SILENT)
		std::cout << ">> +🤴🏾 PresidentialPardonForm param constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
: AForm(src.getName(), 25, 5)
{
	if (!SILENT)
		std::cout << ">> +🤴🏾 PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	if (!SILENT)
		std::cout << ">> -🤴🏾 PresidentialPardonForm destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

void	PresidentialPardonForm::execute(Bureaucrat const *bur, std::string &target) const
{
	if (bur->getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << "✋ " << target << " has been forgiven by Zaphod Beeblebrox." << std::endl;
	}
}

/*
** Operators overload
*/

// Assignment operator
PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &)
{
	if (!SILENT)
		std::cout << ">> =🤴🏾 PresidentialPardonForm assignment operator called" << std::endl;
	return (*this);
}
