/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:29:17 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/26 15:52:40 by mmarinov         ###   ########.fr       */
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

static void deep_copy_test_dog()
{
	print_sep("DEEP COPY TEST - DOG");

	Dog d1;
	d1.getBrain()->setIdea(0, "DOG: original idea");
	d1.getBrain()->setIdea(1, "DOG: idea #1");

	Dog d2(d1); // copy ctor
	d2.getBrain()->setIdea(0, "DOG: copied then modified");

	std::cout << "d1 idea0: " << d1.getBrain()->getIdea(0) << std::endl;
	std::cout << "d2 idea0: " << d2.getBrain()->getIdea(0) << std::endl;

	if (d1.getBrain()->getIdea(0) == d2.getBrain()->getIdea(0))
		std::cout << RED << "FAIL: shallow copy detected (Dog copy ctor)" << RESET << std::endl;
	else
		std::cout << GREEN << "OK: deep copy (Dog copy ctor)" << RESET << std::endl;

	Dog d3;
	d3 = d1; // operator=

	d3.getBrain()->setIdea(1, "DOG: assigned then modified");
	std::cout << "d1 idea1: " << d1.getBrain()->getIdea(1) << std::endl;
	std::cout << "d3 idea1: " << d3.getBrain()->getIdea(1) << std::endl;

	if (d1.getBrain()->getIdea(1) == d3.getBrain()->getIdea(1))
		std::cout << RED << "FAIL: shallow copy detected (Dog operator=)" << RESET << std::endl;
	else
		std::cout << GREEN << "OK: deep copy (Dog operator=)" << RESET << std::endl;

	// Self-assignment test (should not crash, should not corrupt memory)
	Dog& aliasD3 = d3;
	d3 = aliasD3;
	std::cout << GREEN << "OK: self-assignment did not crash" << RESET << std::endl;
}

static void deep_copy_test_cat()
{
	print_sep("DEEP COPY TEST - CAT");

	Cat c1;
	c1.getBrain()->setIdea(0, "CAT: original idea");
	c1.getBrain()->setIdea(2, "CAT: idea #2");

	Cat c2(c1);
	c2.getBrain()->setIdea(0, "CAT: copied then modified");

	std::cout << "c1 idea0: " << c1.getBrain()->getIdea(0) << std::endl;
	std::cout << "c2 idea0: " << c2.getBrain()->getIdea(0) << std::endl;

	if (c1.getBrain()->getIdea(0) == c2.getBrain()->getIdea(0))
		std::cout << RED << "FAIL: shallow copy detected (Cat copy ctor)" << RESET << std::endl;
	else
		std::cout << GREEN << "OK: deep copy (Cat copy ctor)" << RESET << std::endl;

	Cat c3;
	c3 = c1;

	c3.getBrain()->setIdea(2, "CAT: assigned then modified");
	std::cout << "c1 idea2: " << c1.getBrain()->getIdea(2) << std::endl;
	std::cout << "c3 idea2: " << c3.getBrain()->getIdea(2) << std::endl;

	if (c1.getBrain()->getIdea(2) == c3.getBrain()->getIdea(2))
		std::cout << RED << "FAIL: shallow copy detected (Cat operator=)" << RESET << std::endl;
	else
		std::cout << GREEN << "OK: deep copy (Cat operator=)" << RESET << std::endl;
	Cat& aliasC3 = c3;
	aliasC3 = c3;
	std::cout << GREEN << "OK: self-assignment did not crash" << RESET << std::endl;
}

static void polymorphism_test()
{
	print_sep("POLYMORPHISM TEST");

	const Animal* a1 = new Dog();
	const Animal* a2 = new Cat();

	std::cout << "a1 type: " << a1->getType() << std::endl;
	std::cout << "a2 type: " << a2->getType() << std::endl;

	a1->makeSound();
	a2->makeSound();

	print_sep("DELETE THROUGH Animal* (VIRTUAL DTOR REQUIRED)");
	delete a2;
	delete a1;
}

static void array_test()
{
	print_sep("ARRAY TEST (SUBJECT STYLE)");

	const int N = 6;
	Animal* arr[N];

	int i = 0;
	while (i < N)
	{
		if (i < N / 2)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
		i++;
	}

	i = 0;
	while (i < N)
	{
		delete arr[i]; // must call derived dtors
		i++;
	}
	std::cout << GREEN << "OK: array allocation/deletion finished" << RESET << std::endl;
}

static void wrong_polymorphism_test()
{
	print_sep("WRONG POLYMORPHISM TEST");

	const WrongAnimal* w1 = new WrongAnimal();
	const WrongAnimal* w2 = new WrongCat();

	w1->makeSound();
	w2->makeSound(); // will call WrongAnimal::makeSound (no virtual)

	print_sep("DELETE THROUGH WrongAnimal* (NO VIRTUAL DTOR)");
	delete w2;
	delete w1;
}

int main()
{
	deep_copy_test_dog();
	deep_copy_test_cat();
	polymorphism_test();
	array_test();
	wrong_polymorphism_test();

	print_sep("END");
	return 0;
}
