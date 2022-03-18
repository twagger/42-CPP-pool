/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:15:39 by twagner           #+#    #+#             */
/*   Updated: 2022/03/18 16:21:29 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template< typename T >
void	swap(T a, T b)
{
	T	swap;

	swap = a;
	a = b;
	b = swap;
}

template< typename T >
T	&min(T &a, T &b)
{
	if (a < b)
		return (a);
	return (b);
}

template< typename T >
T	&max(T &a, T &b)
{
	if (a > b)
		return (a);
	return (b);
}
