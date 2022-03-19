/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:58:41 by twagner           #+#    #+#             */
/*   Updated: 2022/03/19 11:49:01 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <iomanip>

template< typename T>
void	ft_print(T item)
{
	std::cout << " " << item << " |";
}

template<>
void	ft_print(float item)
{
	std::cout << std::setprecision(1) << std::fixed << " " << item << " |";
}

template< typename T>
void	ft_print_colored(T item)
{
	std::cout << "\033[1;32m" << item << "\033[0m" << std::endl;
}

int main(void)
{
	// TEST 1
	std::cout << "\033[1;35m ---[ 1. Print every element of a char array ]--- \033[0m" << std::endl;
	char	arr[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
	iter<char>(arr, 6, ft_print<char>);
	
	// TEST 2
	std::cout << std::endl << std::endl;
	std::cout << "\033[1;35m ---[ 2. Print every element of an int array ]--- \033[0m" << std::endl;
	int	arr2[6] = {1, 42, 21, -85, 18, 24587};
	iter<int>(arr2, 6, ft_print<int>);

	// TEST 3
	std::cout << std::endl << std::endl;
	std::cout << "\033[1;35m ---[ 3. Print colored every element of a string array ]--- \033[0m" << std::endl;
	std::string	arr3[4] = {"hello", "how", "are", "you"};
	iter<std::string>(arr3, 4, ft_print_colored<std::string>);

	// TEST 4
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ 4. Wrong size for a string array ]--- \033[0m" << std::endl;
	std::string	arr4[4] = {"hello", "how", "are", "you"};
	iter<std::string>(arr4, 2, ft_print_colored<std::string>);

	// TEST 5
	std::cout << std::endl << std::endl;
	std::cout << "\033[1;35m ---[ 5. Wrong size for a float array (causes valgrind warnings but it is for test purpose) ]--- \033[0m" << std::endl;
	float arr5[6] = {1, 42, 21, -85.38, 18, 42.0};
	iter<float>(arr5, 10, ft_print<float>);

	// END OF MAIN
	std::cout << std::endl << std::endl;
	std::cout << "\033[1;35m >>> End of main <<<\033[0m" << std::endl;
	return (0);
}