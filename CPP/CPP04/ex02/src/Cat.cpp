/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:31:07 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/26 16:50:18 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Colors.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat")
{
	brain = new Brain();
	std::cout << BOLD << MAGENTA << "[Cat] Default constructor" << RESET << std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy)
{
	brain = new Brain(*copy.brain);
	std::cout << BOLD << MAGENTA << "[Cat] Copy constructor" << RESET << std::endl;
}

Cat &Cat::operator=(Cat const &copy)
{
	std::cout << BOLD << MAGENTA << "[Cat] Copy assignment" << RESET << std::endl;
	if (this != &copy)
	{
		Animal::operator=(copy);
		delete brain;
		brain = new Brain(*copy.brain);
	}
	return *this;
}

Cat::~Cat(void)
{
	delete brain;
	std::cout << BOLD << MAGENTA << "[Cat] Destructor" << RESET << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << GREEN << "[Cat] Meow!" << RESET << std::endl;
}

Brain* Cat::getBrain()
{
	return this->brain;
}

const Brain* Cat::getBrain() const
{
	return this->brain;
}

