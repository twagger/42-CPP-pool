/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:53:37 by twagner           #+#    #+#             */
/*   Updated: 2022/03/27 23:00:35 by twagner          ###   ########.fr       */
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
void	easyfind(T container, int to_find)
{
	typename T::iterator	it;

	it = std::find(container.begin(), container.end(), to_find);
	if (it == container.end())
		throw std::runtime_error("The value is not in the container");
	std::cout << "I found it : " << *it << ", at this address : " << &*it << std::endl;
}

template <typename T>
void	easyfindWithControl(const T &t, int to_find, typename T::iterator*)
{
	easyfind(t, to_find);
}

void	easyfindWithControl(...)
{
	throw std::runtime_error("The container doesn't have iterators");
}
