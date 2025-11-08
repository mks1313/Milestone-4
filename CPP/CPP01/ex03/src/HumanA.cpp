/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:06:24 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/08 22:31:01 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Colors.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon): name_(name), weapon_(weapon) {
	std::cout << GREEN << "HumanA " << name << RESET << CYAN << " created with " \
		<< RESET << YELLOW << weapon.getType() << RESET << std::endl;
}

HumanA::~HumanA(void) {
	std::cout << GREEN << "HumanA "  << name_ << RESET << RED << " destroyed" << RESET << std::endl;
}

void HumanA::attack(void) {
	std::cout << GREEN <<  name_ << RESET << BLUE " attack with their " \
		<< RESET << YELLOW << weapon_.getType() << RESET << std::endl;
}
