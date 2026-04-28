/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:08:51 by dasimoes          #+#    #+#             */
/*   Updated: 2026/04/28 19:16:51 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iterator>
# include <algorithm>
# include <numeric>

class Span
{
	private:
		std::vector<int>	data;
		unsigned int		cap;
	public:
		Span();
		~Span();
		Span( unsigned int N );
		Span( const Span& other );
		Span&	operator=( const Span& other );
		void			addNumber( int num );
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		class	OverAddingException: public std::exception
		{
			virtual const char*	what() const throw();
		};
		class	NoSpanException: public std::exception
		{
			virtual const char*	what() const throw();
		};
		template <typename T>
		void			addRange( T b, T e )
		{
			if (this->data.size() + std::distance(b, e) > this->cap)
				throw (OverAddingException());
			for (; b != e; b++)
				this->data.push_back(*b);
		}
};

#endif
