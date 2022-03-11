/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:14:41 by twagner           #+#    #+#             */
/*   Updated: 2022/03/08 17:34:07 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		// Constructors and destructor
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		virtual	~ShrubberyCreationForm(void);

		// operator overload
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);

		// accessor
		std::string	getTarget(void) const;

		// member functions
		virtual void	execute(Bureaucrat const &executor) const;
	
	private:
		std::string	_target;
};

#endif
