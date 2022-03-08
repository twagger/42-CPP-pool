/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:14:41 by twagner           #+#    #+#             */
/*   Updated: 2022/03/08 17:21:38 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP
# include <iostream>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class ShruberryCreationForm : public AForm
{
	public:
		// Constructors and destructor
		ShruberryCreationForm(void);
		ShruberryCreationForm(std::string target);
		ShruberryCreationForm(ShruberryCreationForm const &src);
		virtual	~ShruberryCreationForm(void);

		// operator overload
		ShruberryCreationForm	&operator=(ShruberryCreationForm const &rhs);

		// accessor
		std::string	getTarget(void) const;

		// member functions
		virtual void	execute(Bureaucrat const &executor) const;
	
	private:
		std::string	_target;
};

#endif
