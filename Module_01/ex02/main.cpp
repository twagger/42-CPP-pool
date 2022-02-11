/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:12:03 by twagner           #+#    #+#             */
/*   Updated: 2022/02/11 12:45:00 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "----------------------------" << std::endl;
	std::cout << "|        ADDRESSES         |" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "str address : " << &str << std::endl; 
	std::cout << "string PTR  : " << stringPTR << std::endl; 
	std::cout << "string REF  : " << &stringREF << std::endl; 
	std::cout << "----------------------------" << std::endl;
	std::cout << "|          VALUES          |" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "str value        : " << str << std::endl; 
	std::cout << "string PTR value : " << *stringPTR << std::endl; 
	std::cout << "string REF value : " << stringREF << std::endl; 
	return (0);
}
