/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:31:05 by twagner           #+#    #+#             */
/*   Updated: 2022/02/12 11:19:54 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include "Contact.hpp"

/*
** Non member attributes
*/

int	Contact::_nb_contact = 0;

/*
** Constructor & destructor
*/

Contact::Contact(void)
{
	std::cout << ">> + Contact constructor called" << std::endl;
	this->_is_oldest = 0;
}

Contact::~Contact(void)
{
	std::cout << ">> - Contact destructor called" << std::endl;
}

/*
** Accessors
*/

void	Contact::setFirstName(std::string firstname)
{
	this->_firstname = firstname;
}

void	Contact::setLastName(std::string lastname)
{
	this->_lastname = lastname;
}

void	Contact::setNickName(std::string nickname)
{
	this->_nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phone_number)
{
	this->_phone_number = phone_number;
}

void	Contact::setDarkestSecret(std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}

void	Contact::incNbContact(void)
{
	Contact::_nb_contact += 1;
}

void	Contact::setOldest(void)
{
	this->_is_oldest = 1;
}

void	Contact::unsetOldest(void)
{
	this->_is_oldest = 0;
}

int	Contact::getNbContact(void)
{
	return (Contact::_nb_contact);
}

std::string	Contact::getFirstName(void) const
{
	return (this->_firstname);
}

std::string	Contact::getLastName(void) const
{
	return (this->_lastname);
}

std::string	Contact::getNickName(void) const
{
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->_phone_number);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->_darkest_secret);
}

int	Contact::isOldest(void) const
{
	return (this->_is_oldest);
}
