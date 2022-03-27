/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:53:20 by twagner           #+#    #+#             */
/*   Updated: 2022/03/27 09:57:44 by twagner          ###   ########.fr       */
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
typename T::iterator	easyfind(T container, int to_find)
{
	typename T::iterator	it;

	it = std::find(container.begin(), container.end(), to_find);
	if (it == container.end())
		throw std::runtime_error("The value is not in the container");
	return (it);
}

template <typename T>
typename T::iterator	easyfindWithControl(const T &t, int to_find, typename T::iterator*)
{
	return (easyfind(t, to_find));
}

int	*easyfindWithControl(...)
{
	throw std::runtime_error("The container doesn't have iterators");
	return (NULL);
}
