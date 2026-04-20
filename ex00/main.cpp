/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:21:09 by dasimoes          #+#    #+#             */
/*   Updated: 2026/04/20 19:39:16 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cout	<< "No arguments supported, try again!\n"
					<< "type in ./easyfind"
					<< std::endl;
		return (1);
	}

	int lookForMe = 42;
	int dontLookForMe = -1;
	int values[] = {55, 0, -8, 100, 42, 9, 2020202, 99, -78, -42};
	const int constValues[] = {55, 0, -8, 100, 42, 9, 2020202, 99, -78, -42};
	
	std::vector<int> vec(values, values + 10);
	std::deque<int> deq(values, values + 10);
	const std::list<int> lis(constValues, constValues + 10);

	std::cout	<< "========= SEQUENCE CONTAINERS TEST ========="
				<< std::endl << std::endl;
	try
	{
		std::vector<int>::iterator itVec = ::easyfind(vec, lookForMe);
		std::cout << "Found " << *itVec << " in vector\n";

		std::deque<int>::iterator itDeq = ::easyfind(deq, lookForMe);
		std::cout << "Found " << *itDeq << " in deque\n";
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout	<< "========= CONST SEQUENCE CONTAINERS TEST ========="
				<< std::endl << std::endl;
	try
	{
		std::list<int>::const_iterator itLis = ::easyfind(lis, lookForMe);
		std::cout << "Found " << *itLis << " in list\n";
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}	

	std::cout << std::endl;

	std::cout	<< "========= EXCEPTION TEST ========="
				<< std::endl << std::endl;
	try
	{
		std::vector<int>::iterator wrongItVec = ::easyfind(vec, dontLookForMe);
		std::cout << "Found " << *wrongItVec << " in vector\n";
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << std::endl;
	return 0;
}
