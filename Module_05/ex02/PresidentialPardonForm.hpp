/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:14:41 by twagner           #+#    #+#             */
/*   Updated: 2022/03/08 16:52:37 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	public:
		// Constructors and destructor
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		virtual	~PresidentialPardonForm(void);

		// operator overload
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);

		// member functions
		void	execute(Bureaucrat const *bur, std::string &target) const;
};

#endif
