/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:53:20 by twagner           #+#    #+#             */
/*   Updated: 2022/03/25 10:56:35 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

template< typename T >
int	easyfind(T container, int to_find)
{
	typename T::const_iterator	it;
	int							index;

	index = 0;
	for (it = container.begin(); it != container.end(); ++it)
	{
		if (*it == to_find)
		{
			if (!SILENT)
				std::cout << "I found it first in position : " << index << std::endl;
			return (*it);
		}
		++index;
	}
	throw std::runtime_error("The value is not in the container");
}
