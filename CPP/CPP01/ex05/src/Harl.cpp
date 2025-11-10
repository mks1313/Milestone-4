/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 21:23:23 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/10 22:44:35 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "Colors.hpp"
#include <iostream>

Harl::Harl(void) {
	std::cout << "A wild Harl has appeared!" << std::endl;
}

Harl::~Harl(void) {
	std::cout << "Wild Harl flew away!" << std::endl;
}

void Harl::debug(void) {
	std::cout << MAGENTA << "[ DEBUG ] " << RESET;
	std::cout << "I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-special-ketchup burger."
		<< " I just love it!" << std::endl;
}

void Harl::info(void) {
	std::cout << BLUE << "[ INFO ] " << RESET;
	std::cout << "I cannot believe adding extra bacon costs more money."
		<< " You don’t put enough! If you did I would not have to ask"
		<< " for it!" << std::endl;
}

void Harl::warning(void) {
	std::cout << YELLOW << "[ WARNING ] " << RESET;
	std::cout << "I think I deserve to have some extra bacon for free."
		<< " I’ve been coming here for years and you just started "
		<< "working here last month." << std::endl;
}

void Harl::error(void) {
	std::cout << RED << "[ ERROR ] " << RESET;
	std::cout << "This is unacceptable, I want to speak to the manager now."
		<< std::endl;
}

void Harl::complain(std::string level) {
	void (Harl::*ptr[4])(void) = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error
	};
	std::string keys[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < 4; ++i) {
		if (keys[i] == level) {
			(this->*ptr[i])();
			return;
		}
	}
}
