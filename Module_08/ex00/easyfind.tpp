/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:53:20 by twagner           #+#    #+#             */
/*   Updated: 2022/03/26 16:54:21 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <algorithm>

#ifdef SILENCE
# define SILENT 1
#else
# define SILENT 0
#endif

template< typename T >
int	easyfind(T container, int to_find)
{
	typename T::iterator	it;

	it = std::find(container.begin(), container.end(), to_find);
	if (it != container.end())
	{
		std::cout << "I found it : " << *it << std::endl;
		return (*it);
	}
	else
		throw std::runtime_error("The value is not in the container");
}

template <typename T>
int easyfindWithControl(const T &t, int to_find, typename T::iterator*)
{
	return (easyfind(t, to_find));
}

int easyfindWithControl(...)
{
	throw std::runtime_error("The container doesn't have iterators");
	return (0);
}
