/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:48:33 by twagner           #+#    #+#             */
/*   Updated: 2022/03/15 17:21:22 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <stdint.h>
#include "Data.hpp"

uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main(void)
{
	Data		my_data;
	Data		*my_data_ptr;
	uintptr_t	my_uint;

	// Data init
	my_data.c = '*';
	my_data.i = 42;
	my_data.f = 42.0f;
	my_data.d = 42.0;

	// TEST 1
	std::cout << std::endl;
	std::cout << "\033[1;35m---[ Serialize my_data ]---\033[0m" << std::endl;
	std::cout << "My data pointer : " << &my_data << std::endl;
	std::cout << "--Serialization--" << std::endl;
	my_uint = serialize(&my_data);
	std::cout << "My uint : " << my_uint << std::endl
			  << "My uint address : " << &my_uint << std::endl;
	std::cout << "--Deserialization--" << std::endl;
	my_data_ptr = deserialize(my_uint);
	std::cout << "My data c : " << my_data_ptr->c << std::endl
			  << "My data i : " << my_data_ptr->i << std::endl
			  << "My data f : " << std::setprecision(1) << std::fixed << my_data_ptr->f << "f" << std::endl
			  << "My data d : " << std::setprecision(1) << std::fixed << my_data_ptr->d << std::endl
			  << "My data address : " << my_data_ptr << std::endl;
	
	// END OF MAIN
	std::cout << std::endl;
	std::cout << "\033[1;35m >>> End of main <<<\033[0m" << std::endl;
	return (0);
}
