/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:29:00 by twagner           #+#    #+#             */
/*   Updated: 2022/02/12 11:21:07 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	std::string	buff;
	PhoneBook	phonebook;

	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT) :" << std::endl;
		std::getline(std::cin, buff);
		if (!buff.compare("ADD"))
		{
			phonebook.addContact();
		}
		else if (!buff.compare("SEARCH"))
		{
			phonebook.printAllContacts();
			phonebook.searchByIndex();
		}
		else if (!buff.compare("EXIT"))
		{
			break ;
		}
		else
			std::cout << "Please enter a VALID command" << std::endl;
	}
	return (0);
}
