/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:24:07 by dasimoes          #+#    #+#             */
/*   Updated: 2026/04/28 20:57:55 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <algorithm>

template <typename T>
class	MutantStack: public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		MutantStack();
		virtual ~MutantStack();
		MutantStack( const MutantStack<T>& other );
		MutantStack<T>&	operator=( const MutantStack& other );
		iterator		begin();
		iterator		end();
		const_iterator	begin() const;
		const_iterator	end() const;
};

# include "MutantStack.tpp"

#endif
