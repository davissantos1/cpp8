/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:21:09 by dasimoes          #+#    #+#             */
/*   Updated: 2026/04/29 13:18:35 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cout	<< "No arguments supported, try again!\n"
					<< "type in ./mutant"
					<< std::endl;
		return (1);
	}

	std::cout	<< "========= PDF MUTANT STACK TEST ========="
				<< std::endl << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << std::endl;
	std::cout	<< "========= MUTANT STACK CREATION AND ATTRIBUTION TEST ========="
				<< std::endl << std::endl;

	MutantStack<char> stacky;
	MutantStack<int> stacky2;
	MutantStack<int> stacky3 = stacky2;

	for (int i = 0; i < 100; i++)
		stacky2.push(2 * i);

	for (int i = 0; i < 100; i++)
		stacky.push('a' + i);

	MutantStack<int> stacky4(stacky2);
	MutantStack<char> stacky5(stacky);
	
	std::cout << "made stacky, stacky2, stacky3, stacky4 and stacky5 for testing\n";

	std::cout << std::endl;

	std::cout	<< "========= INCREMENT / DECREMENT ITERATOR TEST ========="
				<< std::endl << std::endl;

	MutantStack<int>::iterator it2 = stacky2.begin();
	MutantStack<int>::iterator ite2 = stacky2.end();

	it2++;
	ite2--;
	
	for (; it2 != ite2; it2++)
		std::cout << "it2 value: " << *it2 << '\n';

	for (int i = 0; i < 100; i++)
		stacky2.push(2 * i);

	std::cout << std::endl;
	std::cout	<< "========= EXCEPTION TEST ========="
				<< std::endl << std::endl;

	std::cout << "Trying to go beyond the scope of the iterator\n";

	MutantStack<char>::iterator it3 = stacky.begin();
	MutantStack<char>::iterator ite3 = stacky.end();
	try
	{
		it3--;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		ite3++;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout	<< "========= CONST ITERATOR TEST ========="
				<< std::endl << std::endl;

	for (int j = 0; j < 10; j++)
		stacky3.push(j * 3);

	MutantStack<int>::const_iterator itConst = stacky3.begin();
	MutantStack<int>::const_iterator iteConst = stacky3.end();

	itConst++;
	iteConst--;
	++iteConst;
	
//	*itConst = 2;

	for (; itConst != iteConst; itConst++)
		std::cout << "stacky3: " << *itConst << '\n';

	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}
