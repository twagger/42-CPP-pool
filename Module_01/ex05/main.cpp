/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:11:40 by twagner           #+#    #+#             */
/*   Updated: 2022/02/12 10:53:42 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(void)
{
	Karen karen;

	std::cout << "---------------------" << std::endl;
	std::cout << "|      STANDARD     |" << std::endl;
	std::cout << "---------------------" << std::endl;
	karen.complain("DEBUG");
	karen.complain("INFO");
	karen.complain("WARNING");
	karen.complain("ERROR");
	std::cout << "---------------------" << std::endl;
	std::cout << "|     NO COMMENT    |" << std::endl;
	std::cout << "---------------------" << std::endl;
	karen.complain("");
	karen.complain("debug");
	karen.complain("INFNO");
	return (0);
}
