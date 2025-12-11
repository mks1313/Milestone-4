/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:43:49 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/11 21:23:57 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "Colors.hpp"
#include <iostream>

int main(void)
{
	std::cout << BOLD << BLUE << "\n=== SCAVTRAP TESTS ===\n" << RESET;

	ScavTrap s1("Guardian");
	ScavTrap s2(s1);

	s1.print_msg();
	s2.print_msg();

	std::cout << BOLD << MAGENTA << "\n--- ScavTrap attacks ---\n" << RESET;
	s1.attack("an intruder");

	std::cout << BOLD << YELLOW << "\n--- Gate keeper mode ---\n" << RESET;
	s1.guardGate();

	std::cout << BOLD << CYAN << "\n--- Taking damage ---\n" << RESET;
	s1.takeDamage(30);
	s1.print_msg();

	std::cout << BOLD << GREEN << "\n--- Repairing ---\n" << RESET;
	s1.beRepaired(20);
	s1.print_msg();

	std::cout << BOLD << WHITE << "\n=== END ===\n" << RESET;
	return 0;
}
