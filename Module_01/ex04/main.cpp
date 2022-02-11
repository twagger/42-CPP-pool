/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:11:40 by twagner           #+#    #+#             */
/*   Updated: 2022/02/11 16:32:27 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

int	string_replacer(std::string filepath, std::string s1, std::string s2)
{
	std::ostringstream	tmp_stream;
	std::ifstream		file(filepath);
	std::ofstream		rep_file(filepath.append(".replace"));
	std::string			tmp_string;
	std::size_t			pos;
	
	if (!file.is_open())
	{
		std::cout << "Error : cannot open file." << std::endl;
		return (1);
	}
	tmp_stream << file.rdbuf();
	tmp_string = tmp_stream.str();
	pos = tmp_string.find(s1);
	while (pos != std::string::npos)
	{
		rep_file << tmp_string.substr(0, pos);
		rep_file << s2;
		tmp_string = tmp_string.substr(pos + s1.size(), tmp_string.npos);
		pos = tmp_string.find(s1);
	}
	if (!tmp_string.empty())
		rep_file << tmp_string;
	file.close();
	rep_file.close();
	return (0);
}

int	main(int ac, char **av)
{
	std::string	filepath;
	std::string	s1;
	std::string	s2;

	if (ac != 4)
	{
		std::cerr << "Error : wrong number of arguments." << std::endl;
		return (1);
	}
	filepath = av[1];
	s1 = av[2];
	s2 = av[3];
	if (string_replacer(filepath, s1, s2) > 0)
		return (1);
	return (0);
}
