/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:31:13 by twagner           #+#    #+#             */
/*   Updated: 2022/02/08 12:30:25 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

class Contact
{
	private:

		// Attributes
		std::string	_phone_number;
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_darkest_secret;
		int			_is_oldest;
		static int	_nb_contact;
	
	public:

		// Constructor & Destructor
		Contact(void);
		~Contact(void);

		// Accessors
		static int	getNbContact(void);
		static void	incNbContact(void);

		void		setPhoneNumber(std::string);
		void		setFirstName(std::string);
		void		setLastName(std::string);
		void		setNickName(std::string);
		void		setDarkestSecret(std::string);
		void		setOldest(void);
		void		unsetOldest(void);

		std::string	getPhoneNumber(void) const;
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickName(void) const;
		std::string	getDarkestSecret(void) const;
		int			isOldest(void) const;
};

#endif