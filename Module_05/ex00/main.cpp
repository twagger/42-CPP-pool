/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:12:03 by twagner           #+#    #+#             */
/*   Updated: 2022/03/08 11:54:06 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	// TEST 1
	std::cout << "\033[1;35m---[ Bureaucrat with minimum level (150) ]---\033[0m" << std::endl;
	Bureaucrat	bob("bob", 150);
	std::cout << bob << std::endl;
	try
	{
		bob.decreaseGrade();
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		bob.increaseGrade();
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << bob << std::endl;
	
	// TEST 2
	std::cout << std::endl;
	std::cout << "\033[1;35m---[ Bureaucrat with maximum level (1) ]---\033[0m" << std::endl;
	Bureaucrat	*max = new Bureaucrat("max", 1);
	std::cout << *max << std::endl;
	try
	{
		max->increaseGrade();
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		max->decreaseGrade();
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *max << std::endl;
	delete max;

	// TEST 3
	std::cout << std::endl;
	std::cout << "\033[1;35m---[ Bureaucrat with too low level (151) ]---\033[0m" << std::endl;
	try
	{
		Bureaucrat	billy("billy", 151);
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// TEST 4
	std::cout << std::endl;
	std::cout << "\033[1;35m---[ Bureaucrat with too high level (0) ]---\033[0m" << std::endl;
	try
	{
		Bureaucrat	brenda("brenda", 0);
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "\033[1;35m >>> End of main <<<\033[0m" << std::endl;
	return (0);
}