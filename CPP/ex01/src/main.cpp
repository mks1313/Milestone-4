/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:50:36 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/01 11:41:03 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Colors.hpp"

static void printBanner(void)
{
	std::cout << CYAN << "╔══════════════════════════════════════════════════════════╗\n";
	std::cout << "║" << RESET << BOLD << "               📞  MY AWESOME PHONEBOOK  📖               "  << RESET << CYAN << "║\n";
	std::cout << "╠══════════════════════════════════════════════════════════╣\n";
	std::cout << "║" << RESET << "               Commands: " << GREEN << "ADD" << RESET
	          << ", " << YELLOW << "SEARCH" << RESET
	          << ", " << RED << "EXIT" << RESET
	          << "                " << CYAN << "║\n";
	std::cout << "╚══════════════════════════════════════════════════════════╝"
	          << RESET << "\n\n";
}

int main()
{
	std::signal(SIGQUIT, SIG_IGN);
	printBanner();

	PhoneBook pb;
	std::string command;

	while (true)
	{
		std::cout << MAGENTA << "Enter command → " << RESET;
		if (!std::getline(std::cin, command))
			break;

		if (command == "ADD")
			pb.add();
		else if (command == "SEARCH")
			pb.search();
		else if (command == "EXIT")
			break;
		else
			std::cout << RED << "⚠️  Invalid command. Try again."
			          << RESET << std::endl;
	}
	std::cout << CYAN << "\n👋 Exiting PhoneBook... Goodbye!\n" << RESET;
	return 0;
}
