/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:39:00 by twagner           #+#    #+#             */
/*   Updated: 2022/02/12 11:21:57 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONENOOK_HPP

# include "Contact.hpp"
# define NB_CONTACTS 8

class PhoneBook
{
	private:

		// Attributes
		Contact	_contact_arr[NB_CONTACTS];

	public:
	
		// Constructor & Destructor
		PhoneBook(void);
		~PhoneBook(void);
		
		// Accessors
		void	addContact(void);
		void	addOneContact(std::string fn, std::string ln, \
					std::string nn, std::string pn, std::string ds);
		void	searchByIndex(void) const;
		void	printOneContact(int i) const;
		void	printAllContacts(void) const;
		int		getSlot(void) const;
};

#endif