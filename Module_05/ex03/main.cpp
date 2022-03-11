/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:12:03 by twagner           #+#    #+#             */
/*   Updated: 2022/03/11 12:20:50 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Intern		noNameGuy;
	Bureaucrat	bob("bob", 5);
	AForm		*form;
	
	std::cout << bob << std::endl;
	
	// TEST 1
	std::cout << std::endl;
	std::cout << "\033[1;35m---[ Intern create a Shrubbery form ]---\033[0m" << std::endl;
	form = noNameGuy.makeForm("shrubbery creation", "forest");
	bob.signForm(form);
	bob.executeForm(form);
	delete form;

	// TEST 2
	std::cout << std::endl;
	std::cout << "\033[1;35m---[ Intern create a Robotomy form ]---\033[0m" << std::endl;
	form = noNameGuy.makeForm("robotomy request", "Bender");
	bob.signForm(form);
	bob.executeForm(form);
	delete form;

	// TEST 3
	std::cout << std::endl;
	std::cout << "\033[1;35m---[ Intern create a Presidential form ]---\033[0m" << std::endl;
	form = noNameGuy.makeForm("presidential pardon", "me");
	bob.signForm(form);
	bob.executeForm(form);
	delete form;

	// TEST 4
	std::cout << std::endl;
	std::cout << "\033[1;35m---[ Intern create a Wrong form ]---\033[0m" << std::endl;
	try
	{
		form = noNameGuy.makeForm("wrong", "me");
	}
	catch (Intern::formDoesNotExistException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// TEST 5
	std::cout << std::endl;
	std::cout << "\033[1;35m---[ Intern create a Presidential form with empty target ]---\033[0m" << std::endl;
	try
	{
		form = noNameGuy.makeForm("wrong", "");
	}
	catch (Intern::noTargetException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// END OF MAIN
	std::cout << std::endl;
	std::cout << "\033[1;35m >>> End of main <<<\033[0m" << std::endl;
	return (0);
}
