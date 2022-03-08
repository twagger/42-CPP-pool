/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:14:41 by twagner           #+#    #+#             */
/*   Updated: 2022/03/08 16:34:34 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP
# include <iostream>
# include "Form.hpp"

class Bureaucrat;

class ShruberryCreationForm : public AForm
{
	public:
		// Constructors and destructor
		ShruberryCreationForm(void);
		ShruberryCreationForm(std::string name);
		ShruberryCreationForm(ShruberryCreationForm const &src);
		virtual	~ShruberryCreationForm(void);

		// operator overload
		ShruberryCreationForm	&operator=(ShruberryCreationForm const &rhs);

		// member functions
		void	execute(Bureaucrat const *bur, std::string &target, unsigned int nbTree) const;
};

#endif
