/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:31:41 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/26 16:39:48 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Colors.hpp"
#include <iostream>

Dog::Dog(void) : Animal("Dog")
{
	brain = new Brain();
	std::cout << BOLD << BLUE << "[Dog] Default constructor" << RESET << std::endl;
}

Dog::Dog(Dog const &copy) : Animal(copy)
{
	brain = new Brain(*copy.brain);
	std::cout << BOLD << BLUE << "[Dog] Copy constructor" << RESET << std::endl;
}

Dog &Dog::operator=(Dog const &copy)
{
	std::cout << BOLD << BLUE << "[Dog] Copy assignment" << RESET << std::endl;
	if (this != &copy)
	{
		Animal::operator=(copy);
		delete brain;
		brain = new Brain(*copy.brain);
	}
	return *this;
}

Dog::~Dog(void)
{
	delete brain;
	std::cout << BOLD << BLUE << "[Dog] Destructor" << RESET << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << RED << "[Dog] Woof!" << RESET << std::endl;
}

const Brain* Dog::getBrain() const
{
	return this->brain;
}

Brain* Dog::getBrain()
{
	return this->brain;
}
