/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:20:12 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/20 12:20:18 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Colors.hpp"
#include <iostream>

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << BOLD << RED << "[WrongCat] Default constructor" << RESET << std::endl;
}

WrongCat::WrongCat(const std::string& type)
{
	this->type = type;
	std::cout << BOLD << RED << "[WrongCat] Param constructor" << RESET << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal(copy)
{
	std::cout << BOLD << RED << "[WrongCat] Copy constructor" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &copy)
{
	std::cout << BOLD << RED << "[WrongCat] Copy assignment" << RESET << std::endl;
	if (this != &copy)
		WrongAnimal::operator=(copy);
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << BOLD << RED << "[WrongCat] Destructor" << RESET << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << RED << "[WrongCat] Meow?? (but nobody hears it via base pointer)" 
	          << RESET << std::endl;
}
