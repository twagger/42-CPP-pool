/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:14:41 by twagner           #+#    #+#             */
/*   Updated: 2022/03/08 17:22:22 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		// Constructors and destructor
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		virtual	~RobotomyRequestForm(void);

		// operator overload
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);

		// accessor
		std::string	getTarget(void) const;

		// member functions
		void	execute(Bureaucrat const &executor) const;

	private:
		std::string	_target;
};

#endif
