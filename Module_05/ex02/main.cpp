/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:12:03 by twagner           #+#    #+#             */
/*   Updated: 2022/03/08 17:35:20 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	// TEST 1
	std::cout << "\033[1;35m---[ Bureaucrat (100) and Shrubbery form ]---\033[0m" << std::endl;
	Bureaucrat				bob("bob", 100);
	ShrubberyCreationForm	*shruForm = new ShrubberyCreationForm("SC42");
	std::cout << bob << std::endl;
	bob.signForm(shruForm);
	bob.executeForm(shruForm);

	std::cout << std::endl;
	std::cout << "\033[1;35m >>> End of main <<<\033[0m" << std::endl;
	delete shruForm;
	return (0);
}