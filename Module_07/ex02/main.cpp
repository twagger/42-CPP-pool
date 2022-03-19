/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:54:54 by twagner           #+#    #+#             */
/*   Updated: 2022/03/19 15:53:21 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <stdexcept>

int main(void)
{
	// TEST 1
	std::cout << "\033[1;35m ---[ 1. Creation of an Array with 2 ints ]--- \033[0m" << std::endl;
	Array<int>	arr1(2);
	for (int i = 0; i < 2; i++)
	{
		std::cout << "Default value [" << i << "] : " << arr1[i] << std::endl;
	}

	// TEST 2
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ 2. Accessing an out of range value ]--- \033[0m" << std::endl;
	try
	{
		std::cout << "Default value [5] : " << arr1[5] << std::endl;
	}
	catch(const std::out_of_range &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	// TEST 3
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ 3. Update of values in the array ]--- \033[0m" << std::endl;
	arr1[0] = 8;
	std::cout << "Updated value [0] : " << arr1[0] << std::endl;
	try
	{
		arr1[5] = 42;
		std::cout << "Updated value [5] : " << arr1[5] << std::endl;
	}
	catch(const std::out_of_range &e)
	{
		std::cerr << "Updated value [5] : " << e.what() << std::endl;
	}
	
	// TEST 4
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ 4. Creation of an array by copy ]--- \033[0m" << std::endl;
	Array<int>	arr2(arr1);
	std::cout << "Original array : " << &arr1 << std::endl;
	std::cout << "Copied array : " << &arr2 << std::endl;

	// TEST 5
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ 5. Update of values in the copied array ]--- \033[0m" << std::endl;
	arr2[0] = 42;
	arr2[1] = -58;
	std::cout << "Original array [0] : " << arr1[0] << std::endl;
	std::cout << "Original array [1] : " << arr1[1] << std::endl;
	std::cout << "Copied array [0] : " << arr2[0] << std::endl;
	std::cout << "Copied array [1] : " << arr2[1] << std::endl;

	// TEST 6
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ 6. Creation of an Array with 5 std::string ]--- \033[0m" << std::endl;
	Array<std::string>	arr3(5);
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Default value [" << i << "] : " << arr3[i] << std::endl;
	}

	// END OF MAIN
	std::cout << std::endl;
	std::cout << "\033[1;35m >>> End of main <<<\033[0m" << std::endl;
	return (0);
}