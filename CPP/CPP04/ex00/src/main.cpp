/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:29:17 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/20 12:22:25 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Colors.hpp"

static void print_sep(const std::string& title)
{
	std::cout << "\n" << BOLD << CYAN
			  << "========== " << title << " =========="
			  << RESET << "\n" << std::endl;
}

int main()
{
	print_sep("ANIMAL POLYMORPHISM (CORRECT)");

	const Animal* meta = new Animal();
	const Animal* dog  = new Dog();
	const Animal* cat  = new Cat();

	std::cout << "dog type: " << dog->getType() << std::endl;
	std::cout << "cat type: " << cat->getType() << std::endl;

	cat->makeSound();   // should be cat sound
	dog->makeSound();   // should be dog sound
	meta->makeSound();  // animal sound

	// Test with references (still polymorphic)
	print_sep("ANIMAL VIA CONST REFERENCES");

	const Animal& refDog = *dog;
	const Animal& refCat = *cat;
	refDog.makeSound();
	refCat.makeSound();

	// Delete as Animal* (virtual destructor must work)
	print_sep("DELETING AS Animal* (DESTRUCTORS ORDER)");

	delete cat;
	delete dog;
	delete meta;

	print_sep("WRONG POLYMORPHISM (INTENTIONALLY WRONG)");

	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wcat  = new WrongCat();

	std::cout << "wmeta type: " << wmeta->getType() << std::endl;
	std::cout << "wcat type:  " << wcat->getType() << std::endl;

	wcat->makeSound();   // should output WrongAnimal sound (NOT WrongCat)
	wmeta->makeSound();

	print_sep("DELETING AS WrongAnimal* (NO VIRTUAL DESTRUCTOR)");

	delete wcat;
	delete wmeta;

	print_sep("END");
	return 0;
}
