/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:14:41 by twagner           #+#    #+#             */
/*   Updated: 2022/03/08 17:29:26 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>

class AForm;

class Intern
{
	public:
		// Constructors and destructor
		Intern(void);
		Intern(Intern const &src);
		~Intern(void);

		// operator overload
		Intern	&operator=(Intern const &rhs);

		// accessors

		// member functions
		AForm	*makeForm(std::string name, std::string target) const;

		// exceptions
		class formDoesNotExistException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class noTargetException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

	private:
		AForm	*createShrubberyForm(std::string target) const;
		AForm	*createRobotomyForm(std::string target) const;
		AForm	*createPresidentialForm(std::string target) const;
};

typedef AForm	*(Intern::*FormCreator)(std::string) const;

#endif
