/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:14:41 by twagner           #+#    #+#             */
/*   Updated: 2022/03/08 16:26:20 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>

class Bureaucrat;

class Form
{
	public:
		// Constructors and destructor
		Form(void);
		Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
		Form(Form const &src);
		~Form(void);

		// operator overload
		Form	&operator=(Form const &rhs);

		// accessors
		std::string		getName(void) const;
		bool			getSignedStatus(void) const;
		unsigned int	getGradeToSign(void) const;
		unsigned int	getGradeToExecute(void) const;

		// member functions
		void	beSigned(const Bureaucrat *bur);

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
		const std::string	_name;
		bool				_isSigned;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;
};

std::ostream	&operator<<(std::ostream &o, Form const &i);

#endif
