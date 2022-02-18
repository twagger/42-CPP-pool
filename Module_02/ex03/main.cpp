/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:12:03 by twagner           #+#    #+#             */
/*   Updated: 2022/02/18 16:06:28 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	std::cout << "-----------------------" << std::endl;
	std::cout << "|        TEST 1       |" << std::endl;
	std::cout << "-----------------------" << std::endl;
	Point p1(1.5, 1.1);
	Point p2(4.0, 4.75);
	Point p3(5.1, 1.22);
	Point point_in(4, 2);
	Point point_out(1, 4);
	std::cout << "Point in  : " << bsp(p1, p2, p3, point_in) << std::endl;
	std::cout << "Point out : " << bsp(p1, p2, p3, point_out) << std::endl;

	std::cout << "-----------------------" << std::endl;
	std::cout << "|        TEST 2       |" << std::endl;
	std::cout << "-----------------------" << std::endl;

	Point p4(-3.2, 0);
	Point p5(3.22, 2.48);
	Point p6(3.5, -2.81);
	Point point_in_2(-1, 0);
	Point point_out_2(-4, 3.2);
	std::cout << "Point in  : " << bsp(p4, p5, p6, point_in_2) << std::endl;
	std::cout << "Point out : " << bsp(p4, p5, p6, point_out_2) << std::endl;

	return (0);
}