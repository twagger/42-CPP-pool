/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:46:14 by twagner           #+#    #+#             */
/*   Updated: 2022/03/20 11:10:40 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP
# include <iostream>

enum	e_types
{
	TT_CHAR,
	TT_INT,
	TT_FLOAT,
	TT_DOUBLE,
	TT_ERROR
};

typedef struct s_type
{
	void		*value;
	int			true_type;
	char		c;
	std::string	c_info;
	int			i;
	std::string	i_info;
	float		f;
	std::string	f_info;
	double		d;
	std::string	d_info;
} 			t_type;

#endif
