/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:19:38 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/20 12:19:44 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "Colors.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << DIM << YELLOW << "[WrongAnimal] Default constructor" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : type(type)
{
	std::cout << DIM << YELLOW << "[WrongAnimal] Param constructor" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy) : type(copy.type)
{
	std::cout << DIM << YELLOW << "[WrongAnimal] Copy constructor" << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &copy)
{
	std::cout << DIM << YELLOW << "[WrongAnimal] Copy assignment" << RESET << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << DIM << YELLOW << "[WrongAnimal] Destructor" << RESET << std::endl;
}

void WrongAnimal::setType(const std::string& type)
{
	this->type = type;
}

std::string WrongAnimal::getType(void) const
{
	return this->type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << YELLOW << "[WrongAnimal] * wrong generic sound *" << RESET << std::endl;
}
