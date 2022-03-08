/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:12:03 by twagner           #+#    #+#             */
/*   Updated: 2022/03/08 17:08:32 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShruberryCreationForm.hpp"

int main(void)
{
	// TEST 1
	std::cout << "\033[1;35m---[ Bureaucrat (100) and Shrubberry form ]---\033[0m" << std::endl;
	Bureaucrat				bob("bob", 100);
	ShruberryCreationForm	shruForm("SC42");
	std::cout << bob << std::endl;
	bob.signForm(shruForm);
	bob.executeForm(shruForm);

	std::cout << std::endl;
	std::cout << "\033[1;35m >>> End of main <<<\033[0m" << std::endl;
	return (0);
}