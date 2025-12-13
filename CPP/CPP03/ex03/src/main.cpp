/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:16:23 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/13 14:16:34 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include "Colors.hpp"
#include <iostream>

int main(void)
{
	std::cout << BOLD << BLUE
	          << "\n========== [1] CONSTRUCTION ==========\n"
	          << RESET;

	DiamondTrap d1("Ruby");

	std::cout << BOLD << BLUE
	          << "\n========== [2] WHO AM I ==========\n"
	          << RESET;

	d1.whoAmI();

	std::cout << BOLD << BLUE
	          << "\n========== [3] INITIAL STATUS ==========\n"
	          << RESET;

	d1.print_msg();

	// ----------------------------------------------------

	std::cout << BOLD << MAGENTA
	          << "\n========== [4] ATTACK TEST ==========\n"
	          << RESET;

	d1.attack("enemy");
	d1.attack("enemy");
	d1.attack("enemy");

	std::cout << BOLD << BLUE
	          << "\n--- Status after attacks ---\n"
	          << RESET;

	d1.print_msg();

	// ----------------------------------------------------

	std::cout << BOLD << CYAN
	          << "\n========== [5] DAMAGE & REPAIR ==========\n"
	          << RESET;

	d1.takeDamage(30);
	d1.takeDamage(50);
	d1.beRepaired(20);

	std::cout << BOLD << BLUE
	          << "\n--- Status after damage & repair ---\n"
	          << RESET;

	d1.print_msg();

	// ----------------------------------------------------

	std::cout << BOLD << YELLOW
	          << "\n========== [6] ENERGY DRAIN ==========\n"
	          << RESET;

	for (int i = 0; i < 60; ++i)
		d1.attack("dummy");

	std::cout << BOLD << BLUE
	          << "\n--- Status after energy drain ---\n"
	          << RESET;

	d1.print_msg();

	std::cout << BOLD << RED
	          << "\n========== [7] ACTIONS WITH 0 ENERGY ==========\n"
	          << RESET;

	d1.attack("ghost");
	d1.beRepaired(10);

	// ----------------------------------------------------

	std::cout << BOLD << MAGENTA
	          << "\n========== [8] COPY CONSTRUCTOR ==========\n"
	          << RESET;

	DiamondTrap d2(d1);
	d2.whoAmI();
	d2.print_msg();

	// ----------------------------------------------------

	std::cout << BOLD << MAGENTA
	          << "\n========== [9] COPY ASSIGNMENT ==========\n"
	          << RESET;

	DiamondTrap d3("Temp");
	d3 = d1;
	d3.whoAmI();
	d3.print_msg();

	// ----------------------------------------------------

	std::cout << BOLD << BLUE
	          << "\n========== [10] DESTRUCTION ORDER ==========\n"
	          << RESET;

	std::cout << DIM
	          << "End of main, destructors will now be called\n"
	          << RESET;

	return 0;
}
