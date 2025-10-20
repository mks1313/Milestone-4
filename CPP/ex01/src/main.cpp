/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:50:36 by mmarinov          #+#    #+#             */
/*   Updated: 2025/10/20 23:02:41 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main() {
	PhoneBook pb;
	std::string command;

	while(42) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break;

		if (command == "ADD")
			pb.add();
		else if (command == "SEARCH")
			pb.search();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid input, please enter a valid command example: ADD, SEARCH, EXIT" << std::endl;
	}
	return (0);
}
