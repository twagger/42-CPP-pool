/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:07 by twagner           #+#    #+#             */
/*   Updated: 2022/03/11 09:44:44 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

/*
** Constructor and destructor
*/

Intern::Intern(void)
{
	if (!SILENT)
		std::cout << ">> +🐶 Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &src)
{
	if (!SILENT)
		std::cout << ">> +🐶 Intern copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern(void)
{
	if (!SILENT)
		std::cout << ">> -🐶 Intern destructor called" << std::endl;
}

/*
** Member functions & accessors
*/

AForm	*Intern::makeForm(std::string name, std::string target) const
{
	std::string	forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	FormCreator	create_form[3] = {&Intern::createShrubberyForm, &Intern::createRobotomyForm, &Intern::createPresidentialForm};

	if (target.empty())
		throw Intern::noTargetException();
	else
	{	
		for (int i = 0; i < 3; i++)
		{
			if (forms[i].compare(name) == 0)
			{
				return ((this->*(create_form[i]))(target));
			}
		}
	}
	throw Intern::formDoesNotExistException();
}

AForm	*Intern::createShrubberyForm(std::string target) const
{
	std::cout << "Intern creates shrubbery form with target : " << target << std::endl;
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::createRobotomyForm(std::string target) const
{
	std::cout << "Intern creates robotomy form with target : " << target << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::createPresidentialForm(std::string target) const
{
	std::cout << "Intern creates presidential form with target : " << target << std::endl;
	return (new PresidentialPardonForm(target));
}

/*
** Operators overload
*/

// Assignment operator
Intern	&Intern::operator=(Intern const &)
{
	if (!SILENT)
		std::cout << ">> =🐶 Intern assignment operator called" << std::endl;
	return (*this);
}

// Exceptions

const char	*Intern::formDoesNotExistException::what() const throw()
{
	return ("❌ The form name does not exist !");
}

const char	*Intern::noTargetException::what() const throw()
{
	return ("❌ The target is empty !");
}
