/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:42:17 by twagner           #+#    #+#             */
/*   Updated: 2022/02/12 11:41:27 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

/*
** Constructor & destructor
*/

PhoneBook::PhoneBook(void)
{
	std::cout << ">> + PhoneBook constructor called" << std::endl;
	this->_contact_arr[0].setOldest();
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << ">> - PhoneBook destructor called" << std::endl;
	return ;
}

/*
** Accessors
*/

void	PhoneBook::addContact(void)
{
	std::string	buff_fn;
	std::string	buff_ln;
	std::string	buff_nn;
	std::string	buff_pn;
	std::string	buff_ds;

	while (1)
	{
		std::cout << "Enter the fist name : ";
		std::getline(std::cin, buff_fn);
		std::cout << "Enter the last name : ";
		std::getline(std::cin, buff_ln);
		std::cout << "Enter the nick name : ";
		std::getline(std::cin, buff_nn);
		std::cout << "Enter the phone number : ";
		std::getline(std::cin, buff_pn);
		std::cout << "Enter the darkest secret : ";
		std::getline(std::cin, buff_ds);
		if (!buff_fn.empty() && !buff_ln.empty() && !buff_nn.empty() \
			&& !buff_ds.empty())
			break ;
		else
			std::cout << "\033[1;31mError : all fields are mandatory\033[0m" << std::endl;
	}
	this->addOneContact(buff_fn, buff_ln, buff_nn, buff_pn, buff_ds);
	std::cout << "\033[1;36m>>> Contact added ! <<<\033[0m" << std::endl;
}

void	PhoneBook::addOneContact(std::string fn, std::string ln, \
			std::string nn, std::string pn, std::string ds)
{
	int	index;

	index = this->getSlot();
	this->_contact_arr[index].setFirstName(fn);
	this->_contact_arr[index].setLastName(ln);
	this->_contact_arr[index].setNickName(nn);
	this->_contact_arr[index].setPhoneNumber(pn);
	this->_contact_arr[index].setDarkestSecret(ds);
	if (this->_contact_arr[index].isOldest())
	{
		this->_contact_arr[index].unsetOldest();
		if (index == NB_CONTACTS - 1)
			this->_contact_arr[0].setOldest();
		else
			this->_contact_arr[index + 1].setOldest();
	}
	if (Contact::getNbContact() != NB_CONTACTS)
		Contact::incNbContact();
}


void	PhoneBook::searchByIndex(void) const
{
	std::string	buff;
	int			index;
	int			nb_errors;

	nb_errors = 0;
	while (1)
	{
		std::cout << "Index of the contact to display :";
		std::getline(std::cin, buff);
		try	{
			index = std::stoi(buff);
		}
		catch (std::invalid_argument) {
			index = -1;
		}
		if (index >= 0 && index < Contact::getNbContact())
			break ;
		else
		{
			++nb_errors;
			std::cout << "ERROR : Wrong index." << std::endl;
			if (nb_errors >= 3)
				return ;
		}
	}
	this->printOneContact(index);
}

void	PhoneBook::printOneContact(int i) const
{
	std::cout << "--------------------" << std::endl;
	std::cout << "-- CONTACT DETAIL --" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "First name     : " << this->_contact_arr[i].getFirstName() << std::endl;
	std::cout << "Last name      : " << this->_contact_arr[i].getLastName() << std::endl;
	std::cout << "Nick name      : " << this->_contact_arr[i].getNickName() << std::endl;
	std::cout << "Phone numner   : " << this->_contact_arr[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << this->_contact_arr[i].getDarkestSecret() << std::endl;
	std::cout << "--------------------" << std::endl;
}

static	std::string	getResized(std::string str)
{
	if (str.length() <= 10)
	{
		str.resize(10, ' ');
		return (str);
	}
	else
	{
		str.resize(9);
		str.append(".", 1);
		return (str);
	}
}

void	PhoneBook::printAllContacts(void) const
{
	int	i;
	int	nb_contact;

	nb_contact = Contact::getNbContact();
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|INDEX     |";
	std::cout << "FIRSTNAME |";
	std::cout << "LASTNAME  |";
	std::cout << "NICKNAME  |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	i = -1;
	while (++i < nb_contact)
	{
		std::cout << "|" << i << "         |";
		std::cout << getResized(this->_contact_arr[i].getFirstName()) << "|";
		std::cout << getResized(this->_contact_arr[i].getLastName()) << "|";
		std::cout << getResized(this->_contact_arr[i].getNickName()) << "|" \
			<< std::endl;
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

int	PhoneBook::getSlot(void) const
{
	int	i;
	int	nb_contact;
	int	oldest_i;

	nb_contact = Contact::getNbContact();
	if (nb_contact == NB_CONTACTS)
	{
		i = -1;
		while (++i < nb_contact)
		{
			if (this->_contact_arr[i].isOldest())
				return (i);
		}
	}
	else
		return (nb_contact);
	return (0);
}
