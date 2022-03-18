/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:06:44 by twagner           #+#    #+#             */
/*   Updated: 2022/03/18 12:14:40 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Litteral.hpp"

int	main(int ac, char **av)
{
	char		res_char;
	int			res_int;
	float		res_float;
	double		res_double;

	if (ac != 2)
	{
		std::cerr << "Error : wrong number of arguments." << std::endl;
		return (1);
	}
	Litteral	litteral(av[1]);

	try
	{
		res_char = litteral.toChar();
		std::cout << "char : " << res_char << std::endl;
	}
	catch (Litteral::ImpossibleConversionException &e)
	{
		std::cerr << "char : " << e.what() << std::endl;
	}
	catch (Litteral::NonDisplayableException &e)
	{ 
		std::cerr << "char : " << e.what() << std::endl;
	}

	// Int
	try
	{
		res_int = litteral.toInt();
		std::cout << "int : " << res_int << std::endl;
	}
	catch (Litteral::ImpossibleConversionException &e)
	{
		std::cerr << "int : " << e.what() << std::endl;
	}
	catch (Litteral::NonDisplayableException &e)
	{
		std::cerr << "int : " << e.what() << std::endl;
	}
	catch (Litteral::OverflowException &e)
	{
		std::cerr << "int : " << e.what() << std::endl;
	}
	catch (Litteral::UnderflowException &e)
	{
		std::cerr << "int : " << e.what() << std::endl;
	}

	// Float
	try
	{
		res_float = litteral.toFloat();
		std::cout << std::setprecision(1) << std::fixed
				  << "float : " << res_float << "f" << std::endl;
	}
	catch (Litteral::ImpossibleConversionException &e)
	{
		std::cerr << "float : " << e.what() << std::endl;
	}
	catch (Litteral::NonDisplayableException &e)
	{
		std::cerr << "float : " << e.what() << std::endl;
	}

	// Double
	try
	{
		res_double = litteral.toDouble();
		std::cout << std::setprecision(1) << std::fixed
				  << "double : " << res_double << std::endl;
	}
	catch (Litteral::ImpossibleConversionException &e)
	{
		std::cerr << "double : " << e.what() << std::endl;
	}
	catch (Litteral::NonDisplayableException &e)
	{
		std::cerr << "double : " << e.what() << std::endl;
	}

	return (0);
}