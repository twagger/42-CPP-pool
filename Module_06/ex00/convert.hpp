/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:46:14 by twagner           #+#    #+#             */
/*   Updated: 2022/03/22 09:58:37 by twagner          ###   ########.fr       */
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
	char		*value;
	int			true_type;
	char		c;
	std::string	c_info;
	int			i;
	std::string	i_info;
	float		f;
	std::string	f_info;
	double		d;
	std::string	d_info;
} 				t_type;

size_t	ft_strlen(const char *s);
int		ft_strchr_index(const char *s, int c, int offset);
bool	isNumber(char *str);

void	toChar(t_type *data);
void	toInt(t_type *data);
void	toFloat(t_type *data);
void	toDouble(t_type *data);

void	fromChar(t_type *data);
void	fromInt(t_type *data);
void	fromFloat(t_type *data);
void	fromDouble(t_type *data);

#endif
