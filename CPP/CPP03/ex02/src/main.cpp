/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:43:49 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/11 22:46:59 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "Colors.hpp"
#include <iostream>

int main(void)
{
	std::cout << BOLD << BLUE << "\n========== [1] CONSTRUCTORS ==========\n" << RESET;
	ClapTrap c("Clappy");
	ScavTrap s("Scavy");
	FragTrap f("Fraggy");

	std::cout << BOLD << BLUE << "\n========== [2] INITIAL STATUS ==========\n" << RESET;
	c.print_msg();
	s.print_msg();
	f.print_msg();

	// ------------------------------------------------------------

	std::cout << BOLD << MAGENTA << "\n========== [3] BASIC ATTACKS ==========\n" << RESET;
	c.attack("dummy");
	s.attack("intruder");
	f.attack("enemy");

	// ------------------------------------------------------------

	std::cout << BOLD << CYAN << "\n========== [4] DAMAGE RECEIVED ==========\n" << RESET;
	c.takeDamage(5);
	s.takeDamage(20);
	f.takeDamage(40);

	std::cout << BOLD << BLUE << "\n--- Status after damage ---\n" << RESET;
	c.print_msg();
	s.print_msg();
	f.print_msg();

	// ------------------------------------------------------------

	std::cout << BOLD << GREEN << "\n========== [5] REPAIRS ==========\n" << RESET;
	c.beRepaired(3);
	s.beRepaired(10);
	f.beRepaired(20);

	std::cout << BOLD << BLUE << "\n--- Status after repairs ---\n" << RESET;
	c.print_msg();
	s.print_msg();
	f.print_msg();

	// ------------------------------------------------------------

	std::cout << BOLD << YELLOW << "\n========== [6] SPECIAL METHODS ==========\n" << RESET;
	s.guardGate();
	f.highFivesGuys();

	// ------------------------------------------------------------

	std::cout << BOLD << MAGENTA << "\n========== [7] COPY CONSTRUCTION ==========\n" << RESET;
	FragTrap copyFrag(f);
	copyFrag.print_msg();

	// ------------------------------------------------------------

	std::cout << BOLD << YELLOW << "\n========== [8] COPY ASSIGNMENT ==========\n" << RESET;
	FragTrap assignFrag("Temp");
	assignFrag = f;
	assignFrag.print_msg();

	// ------------------------------------------------------------

	std::cout << BOLD << RED << "\n========== [9] ENERGY DRAIN TEST ==========\n" << RESET;
	for (int i = 0; i < 105; i++)  // hasta drenar
		f.attack("Energy Dummy");

	std::cout << BOLD << BLUE << "\n--- Fraggy after draining energy ---\n" << RESET;
	f.print_msg();

	// ------------------------------------------------------------

	std::cout << BOLD << GREEN << "\n========== [10] ACTIONS WITH 0 ENERGY ==========\n" << RESET;
	f.attack("NoEnergyTarget");
	f.beRepaired(5);

	// ------------------------------------------------------------

	std::cout << BOLD << WHITE << "\n========== END OF TEST ==========\n" << RESET;

	return 0;
}
