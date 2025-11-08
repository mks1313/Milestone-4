/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:07:05 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/08 22:35:43 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Colors.hpp"
#include <iostream>

HumanB::HumanB(std::string name): name_(name), weapon_(NULL) {
	std::cout << GREEN << "HumanB " << name << RESET << WHITE << \
		" Created without weapon" << RESET << std::endl;
}

HumanB::~HumanB(void) {
	std::cout << GREEN <<  "HumanB " << name_ << RESET << RED << " destroyed" << RESET << std::endl;
}

void HumanB::attack(void) {
	if (weapon_)
		std::cout << GREEN << name_ << RESET << BLUE " attack with his " \
			<< RESET << YELLOW << weapon_->getType() << RESET << std::endl;
	else
		std::cout << GREEN << name_ << RESET << BLUE << \
			" attack with bare hands" << RESET << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	weapon_ = &weapon;
	std::cout << YELLOW << weapon.getType() << RESET << CYAN << " was assigned to " \
		RESET << GREEN << name_ << RESET << std::endl;
}
