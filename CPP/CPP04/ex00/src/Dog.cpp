/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:31:41 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/20 11:51:53 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Colors.hpp"
#include <iostream>

Dog::Dog(void) : Animal("Dog")
{
	std::cout << BOLD << BLUE << "[Dog] Default constructor" << RESET << std::endl;
}

Dog::Dog(const std::string& type) : Animal(type)
{
	std::cout << BOLD << BLUE << "[Dog] Param constructor" << RESET << std::endl;
}

Dog::Dog(Dog const &copy) : Animal(copy)
{
	std::cout << BOLD << BLUE << "[Dog] Copy constructor" << RESET << std::endl;
}

Dog &Dog::operator=(Dog const &copy)
{
	std::cout << BOLD << BLUE << "[Dog] Copy assignment" << RESET << std::endl;
	if (this != &copy)
		Animal::operator=(copy);
	return *this;
}

Dog::~Dog(void)
{
	std::cout << BOLD << BLUE << "[Dog] Destructor" << RESET << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << RED << "[Dog] Woof!" << RESET << std::endl;
}
