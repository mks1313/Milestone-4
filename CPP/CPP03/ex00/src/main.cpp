/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:43:49 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/11 19:24:33 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "Colors.hpp"
#include <iostream>

int main(void)
{
	std::cout << BOLD << BLUE << "\n========== [1] OBJECT CONSTRUCTION ==========\n" << RESET;

	ClapTrap A;
	ClapTrap B("Boris");

	std::cout << DIM << "Creating C as a copy of B (C is a clone of Boris)\n" << RESET;
	ClapTrap C(B);

	std::cout << BOLD << BLUE << "\n========== [2] INITIAL STATUS ==========\n" << RESET;
	std::cout << DIM << "A = default ClapTrap\nB = Boris\nC = copy of Boris (same stats as B)\n" << RESET;
	A.print_msg();
	B.print_msg();
	C.print_msg();

	std::cout << BOLD << MAGENTA << "\n========== [3] BASIC ATTACKS ==========\n" << RESET;
	std::cout << DIM << "A attacks Boris, Boris attacks Default, and C (copy of Boris) also attacks Default.\n" << RESET;
	A.attack("Boris");
	B.attack("Default");
	C.attack("Default");

	std::cout << BOLD << CYAN << "\n========== [4] DAMAGE RECEIVED ==========\n" << RESET;
	std::cout << DIM << "B (Boris) and C (copy of Boris) take damage.\n" << RESET;
	B.takeDamage(3);
	C.takeDamage(10);

	std::cout << BOLD << RED << "\n========== [5] ACTIONS WITH 0 HP (C is at 0 HP) ==========\n" << RESET;
	std::cout << DIM << "C tries to attack and repair but has 0 HP, so it cannot act.\n" << RESET;
	C.attack("A");
	C.beRepaired(5);

	std::cout << BOLD << GREEN << "\n========== [6] REPAIRS (A and B) ==========\n" << RESET;
	std::cout << DIM << "A and B repair themselves.\n" << RESET;
	A.beRepaired(4);
	B.beRepaired(2);

	std::cout << BOLD << BLUE << "\n========== [7] STATUS AFTER REPAIRS ==========\n" << RESET;
	A.print_msg();
	B.print_msg();
	C.print_msg();

	std::cout << BOLD << YELLOW << "\n========== [8] COPY ASSIGNMENT ==========\n" << RESET;
	std::cout << DIM << "Creating D(\"Dimitri\") and then assigning D = B (copy assignment).\n" << RESET;
	ClapTrap D("Dimitri");
	D.print_msg();

	std::cout << DIM << "Now doing: D = B;\n" << RESET;
	D = B;

	std::cout << DIM << "D now has the same state as B.\n" << RESET;
	D.print_msg();

	std::cout << BOLD << MAGENTA << "\n========== [9] DRAINING A'S ENERGY ==========\n" << RESET;
	std::cout << DIM << "A will attack until it runs out of energy.\n" << RESET;
	for (int i = 0; i < 12; i++)
		A.attack("training dummy");

	std::cout << BOLD << RED << "\n========== [10] ACTIONS WITH 0 ENERGY (A) ==========\n" << RESET;
	std::cout << DIM << "A tries to attack and repair with 0 energy points.\n" << RESET;
	A.attack("training dummy");
	A.beRepaired(3);

	std::cout << BOLD << GREEN << "\n========== [11] FINAL STATUS ==========\n" << RESET;
	A.print_msg();
	B.print_msg();
	C.print_msg();
	D.print_msg();

	std::cout << BOLD << WHITE << "\n========== END OF TEST ==========\n" << RESET;
	return (0);
}
