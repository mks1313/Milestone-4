/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 21:23:23 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/10 22:37:11 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "Colors.hpp"
#include <iostream>
#include <string>

Harl::Harl(void) {
	std::cout << "A wild Harl has appeared!" << std::endl;
}

Harl::~Harl(void) {
	std::cout << "Wild Harl flew away!" << std::endl;
}

void Harl::debug(void) {
	std::cout << MAGENTA << "[DEBUG    ]" << RESET;
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger.";
	std::cout << " I just love it!" << std::endl;
}

void Harl::info(void) {
	std::cout << BLUE << "[INFO    ]" << RESET;
	std::cout << "I cannot believe adding extra bacon cost more money.";
	std::cout << " You don’t put enough! If you did I would not have to ask";
	std::cout << " for it!" << std::endl;
}

void Harl::warning(void) {
	std::cout << YELLOW << "[WARNING    ]" << RESET;
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << " I’ve been coming here for years and you just started ";
	std::cout << "working here last month." << std::endl;
}

void Harl::error(void) {
	std::cout << RED << "[ERROR    ]" << RESET;
	std::cout << "This is unacceptable, I want to speak to the manager now.";
	std::cout << std::endl;
}

void Harl::complain(std::string level) {
	void (Harl::*ptr_complain[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*ptr_complain[i])();
			break ;
		}
	}
}
