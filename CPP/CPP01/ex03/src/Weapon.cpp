/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:07:36 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/08 22:37:11 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "Colors.hpp"
#include <iostream>

Weapon::Weapon(std::string type): type_(type) {
	std::cout << CYAN << "Weapon was created of type: " << RESET \
		<< YELLOW << type << RESET << std::endl;
}

Weapon::~Weapon(void) {
	std::cout << CYAN << "Weapon of type: " << RESET << YELLOW << type_ << RESET << RED \
		<< " was destroyed" << RESET << std::endl;
}

const std::string& Weapon::getType(void) const {
	return (type_);
}

void Weapon::setType(std::string type) {
	type_ = type;
	std::cout << CYAN << "Weapon type: " << RESET << YELLOW << type << RESET << CYAN << \
		" was assigned" << RESET << std::endl;
}
