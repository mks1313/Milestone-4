/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:00:05 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/26 15:22:29 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Colors.hpp"
#include <iostream>

Brain::Brain(void)
{
	std::cout << BOLD << BLUE << "[Brain] Default constructor" << RESET << std::endl;
	int i = 0;
	while (i < 100)
	{
		this->ideas[i] = "";
		i++;
	}
}

Brain::~Brain(void)
{
	std::cout << BOLD << BLUE << "[Brain] Destructor" << RESET << std::endl;
}

Brain::Brain(Brain const &copy)
{
	std::cout << BOLD << BLUE << "[Brain] Copy constructor" << RESET << std::endl;
	int i = 0;
	while (i < 100)
	{
		this->ideas[i] = copy.ideas[i];
		i++;
	}
}

Brain &Brain::operator=(Brain const &copy)
{
	std::cout << BOLD << BLUE << "[Brain] copy assignment" << RESET << std::endl;
	if (this != &copy)
	{
		int i = 0;
		while (i < 100)
		{
			this->ideas[i] = copy.ideas[i];
			i++;
		}
	}
	return *this;
}

void Brain::setIdea(int i, const std::string& s)
{
	if (i < 0 || i > 99)
		return;
	this->ideas[i] = s;
}

std::string Brain::getIdea(int i) const
{
	if (i < 0 || i >= 100)
		return "";
	return ideas[i];
}
