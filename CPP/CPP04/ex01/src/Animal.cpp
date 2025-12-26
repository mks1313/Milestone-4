/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 11:49:59 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/20 11:51:14 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Colors.hpp"
#include <iostream>

Animal::Animal(void) : type("Animal")
{
	std::cout << DIM << CYAN << "[Animal] Default constructor" << RESET << std::endl;
}

Animal::Animal(const std::string& type) : type(type)
{
	std::cout << DIM << CYAN << "[Animal] Param constructor" << RESET << std::endl;
}

Animal::Animal(Animal const &copy) : type(copy.type)
{
	std::cout << DIM << CYAN << "[Animal] Copy constructor" << RESET << std::endl;
}

Animal &Animal::operator=(Animal const &copy)
{
	std::cout << DIM << CYAN << "[Animal] Copy assignment" << RESET << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return *this;
}

Animal::~Animal(void)
{
	std::cout << DIM << CYAN << "[Animal] Destructor" << RESET << std::endl;
}

void Animal::setType(const std::string& type)
{
	this->type = type;
}

std::string Animal::getType(void) const
{
	return this->type;
}

void Animal::makeSound(void) const
{
	std::cout << YELLOW << "[Animal] * generic animal sound *" << RESET << std::endl;
}
