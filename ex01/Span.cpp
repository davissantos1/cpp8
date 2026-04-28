/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:36:43 by dasimoes          #+#    #+#             */
/*   Updated: 2026/04/28 15:01:21 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::~Span() {}

Span::Span(): cap(0) {}

Span::Span( unsigned int N ):  cap(N) 
{
	this->data.reserve(N);
}

Span::Span( const Span& other )
{
	*this = other;
}

Span&			Span::operator=( const Span& other )
{
	if (this != &other)
	{
		this->cap = other.cap;
		this->data = other.data;
	}
	return (*this);
}

void			Span::addNumber( int num )
{
	if (this->data.size() == this->cap || !this->cap)
		throw (OverAddingException());
	this->data.push_back(num);
}

unsigned int	Span::shortestSpan()
{
	if (this->cap == 1 || !this->cap)
		throw (NoSpanException());
	std::vector<int> tmp = this->data;
	std::sort(tmp.begin(), tmp.end());
	std::vector<int> diff(tmp.size());
	std::adjacent_difference(tmp.begin(), tmp.end(), diff.begin());
	int low = *std::min_element(diff.begin() + 1, diff.end());
	return (low);
}

unsigned int	Span::longestSpan()
{
	if (this->cap == 1 || !this->cap)
		throw (NoSpanException());
	unsigned int low = *std::min_element(this->data.begin(), this->data.end());
	unsigned int high = *std::max_element(this->data.begin(), this->data.end());
	return (high - low);
}

const char*	Span::NoSpanException::what() const throw()
{
	return ("There are no Spans to be calculated! Try again!");
}

const char*	Span::OverAddingException::what() const throw()
{
	return ("There are no more space left in your Span! Try again!");
}
