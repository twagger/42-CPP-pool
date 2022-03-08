/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:12:03 by twagner           #+#    #+#             */
/*   Updated: 2022/03/08 13:35:03 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	// TEST 1
	std::cout << "\033[1;35m---[ Bureaucrat (150) and default form (150) ]---\033[0m" << std::endl;
	Bureaucrat	bob("bob", 150);
	Form		default_form;
	std::cout << bob << std::endl;
	bob.signForm(default_form);

	// TEST 2
	std::cout << std::endl;
	std::cout << "\033[1;35m---[ Bureaucrat (150) and form (50) ]---\033[0m" << std::endl;
	Bureaucrat	max("max", 150);
	Form		form_50("L50", 50, 50);
	std::cout << max << std::endl;
	max.signForm(form_50);

	// TEST 3
	std::cout << std::endl;
	std::cout << "\033[1;35m---[ wrong form (250) ]---\033[0m" << std::endl;
	try
	{
		Form form_250("L250", 250, 250);
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// TEST 4
	std::cout << std::endl;
	std::cout << "\033[1;35m---[ wrong form (0) ]---\033[0m" << std::endl;
	try
	{
		Form form_0("L0", 0, 0);
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\033[1;35m >>> End of main <<<\033[0m" << std::endl;
	return (0);
}