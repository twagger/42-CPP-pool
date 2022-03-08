/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:14:41 by twagner           #+#    #+#             */
/*   Updated: 2022/03/08 16:59:40 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "Form.hpp"

class Bureaucrat
{
	public:
		// Constructors and destructor
		Bureaucrat(void);
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);

		// operator overload
		Bureaucrat	&operator=(Bureaucrat const &rhs);

		// accessors
		std::string		getName(void) const;
		unsigned int	getGrade(void) const;

		// member functions
		void	increaseGrade(void);
		void	decreaseGrade(void);
		void	signForm(AForm &form) const;
		void	executeForm(AForm const &form) const;

		// exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

	private:
		std::string		_name;
		unsigned int	_grade;
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &i);

#endif
