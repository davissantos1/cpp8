/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:21:09 by dasimoes          #+#    #+#             */
/*   Updated: 2026/04/28 15:20:36 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cout	<< "No arguments supported, try again!\n"
					<< "type in ./span"
					<< std::endl;
		return (1);
	}

	std::cout	<< "========= PDF SPAN TEST ========="
				<< std::endl << std::endl;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl;

	std::cout	<< "========= SPAN CREATION AND ATTRIBUTION TEST ========="
				<< std::endl << std::endl;

	std::vector<unsigned int> test(20000, 0);
	Span spanny = Span(20000);
	Span spanny2 = Span(20000);
	Span spanny3 = spanny2;
	Span spanny4 = Span(10);
	Span spanny5 = Span();
	
	std::cout << "Created spanny, spanny2, spanny3, spanny4 and spanny5 for testing!\n";

	std::cout << std::endl;

	std::cout	<< "========= SPAN ADD NUMBER TEST ========="
				<< std::endl << std::endl;
	
	for (unsigned int i = 0; i < 20000; i++)
		spanny.addNumber(i);

	std::cout << "added 20k numbers to spanny\n";

	std::cout << std::endl;
	std::cout	<< "========= SPAN ADD RANGE TEST ========="
				<< std::endl << std::endl;

	spanny2.addRange(test.begin(), test.end());
	std::cout << "added 20k numbers to spanny2 via range function\n";

	std::cout << std::endl;
	std::cout	<< "========= SHORTEST/LONGEST SPAN TEST ========="
				<< std::endl << std::endl;

	std::cout << "Longest span of spanny: " << spanny.longestSpan() << '\n';
	std::cout << "Shortest span of spanny: " << spanny.shortestSpan() << '\n';
	std::cout << "Longest span of spanny2: " << spanny2.longestSpan() << '\n';
	std::cout << "Shortest span of spanny2: " << spanny2.shortestSpan() << '\n';

	std::cout << std::endl;
	std::cout	<< "========= SPAN EXCEPTION TEST ========="
				<< std::endl << std::endl;
	try
	{
		for (unsigned int j = 0; j < 20000; j++)
			spanny4.addNumber(j);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		spanny5.addRange(test.begin(), test.end());
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Longest span of spanny5: " << spanny5.longestSpan() << '\n';
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Shortest span of spanny5: " << spanny5.shortestSpan() << '\n';
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}
