/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:31:07 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/20 11:51:33 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Colors.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat")
{
	std::cout << BOLD << MAGENTA << "[Cat] Default constructor" << RESET << std::endl;
}

Cat::Cat(const std::string& type) : Animal(type)
{
	std::cout << BOLD << MAGENTA << "[Cat] Param constructor" << RESET << std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy)
{
	std::cout << BOLD << MAGENTA << "[Cat] Copy constructor" << RESET << std::endl;
}

Cat &Cat::operator=(Cat const &copy)
{
	std::cout << BOLD << MAGENTA << "[Cat] Copy assignment" << RESET << std::endl;
	if (this != &copy)
		Animal::operator=(copy);
	return *this;
}

Cat::~Cat(void)
{
	std::cout << BOLD << MAGENTA << "[Cat] Destructor" << RESET << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << GREEN << "[Cat] Meow!" << RESET << std::endl;
}
