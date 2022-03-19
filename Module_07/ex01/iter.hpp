/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:08:49 by twagner           #+#    #+#             */
/*   Updated: 2022/03/19 11:30:58 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template< typename T> 
void	iter(T *arr, int size, void (*f)(T))
{
	for (int i = 0; i < size; i++)
	{
		f(arr[i]);
	}
}

#endif