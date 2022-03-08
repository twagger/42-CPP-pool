/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:14:41 by twagner           #+#    #+#             */
/*   Updated: 2022/03/08 16:42:00 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	public:
		// Constructors and destructor
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		virtual	~RobotomyRequestForm(void);

		// operator overload
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);

		// member functions
		void	execute(Bureaucrat const *bur, std::string &target) const;
};

#endif
