/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:12:03 by twagner           #+#    #+#             */
/*   Updated: 2022/03/11 10:02:34 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	// TEST 1
	std::cout << "\033[1;35m---[ Bureaucrat (100) and Shrubbery form ]---\033[0m" << std::endl;
	Bureaucrat				bob("bob", 100);
	ShrubberyCreationForm	*shruForm = new ShrubberyCreationForm("SC01");
	std::cout << bob << std::endl;
	bob.signForm(shruForm);
	bob.executeForm(shruForm);

	// TEST 2
	std::cout << std::endl;
	std::cout << "\033[1;35m---[ Bureaucrat (145) and Shrubbery form ]---\033[0m" << std::endl;
	Bureaucrat				max("max", 145);
	ShrubberyCreationForm	*shruForm2 = new ShrubberyCreationForm("SC02");
	std::cout << max << std::endl;
	max.signForm(shruForm2);
	max.executeForm(shruForm2);

	// TEST 3
	std::cout << std::endl;
	std::cout << "\033[1;35m---[ Bureaucrat (25) and Presidential Pardon form ]---\033[0m" << std::endl;
	Bureaucrat				annie("annie", 25);
	PresidentialPardonForm	*presForm1 = new PresidentialPardonForm("PP01");
	std::cout << annie << std::endl;
	annie.signForm(presForm1);
	annie.executeForm(presForm1);

	// TEST 4
	std::cout << std::endl;
	std::cout << "\033[1;35m---[ Bureaucrat (5) and Presidential Pardon form ]---\033[0m" << std::endl;
	Bureaucrat				minnie("minnie", 5);
	PresidentialPardonForm	*presForm2 = new PresidentialPardonForm("PP02");
	std::cout << minnie << std::endl;
	bob.signForm(presForm2);
	minnie.executeForm(presForm2);

	// TEST 5
	std::cout << std::endl;
	std::cout << "\033[1;35m---[ Bureaucrat (45) and Robotomy Request form ]---\033[0m" << std::endl;
	Bureaucrat				pluto("pluto", 45);
	RobotomyRequestForm		*robotoForm1 = new RobotomyRequestForm("RR01");
	std::cout << pluto << std::endl;
	pluto.signForm(robotoForm1);
	pluto.executeForm(robotoForm1);

	// TEST 6
	std::cout << std::endl;
	std::cout << "\033[1;35m---[ Bureaucrat (72) and Robotomy Request form ]---\033[0m" << std::endl;
	Bureaucrat				donald("donald", 72);
	RobotomyRequestForm		*robotoForm2 = new RobotomyRequestForm("RR02");
	std::cout << donald << std::endl;
	donald.signForm(robotoForm2);
	donald.executeForm(robotoForm2);

	std::cout << std::endl;
	std::cout << "\033[1;35m >>> End of main <<<\033[0m" << std::endl;
	delete shruForm;
	delete shruForm2;
	delete presForm1;
	delete presForm2;
	delete robotoForm1;
	delete robotoForm2;
	return (0);
}