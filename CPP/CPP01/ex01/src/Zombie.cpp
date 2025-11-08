/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:04:36 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/08 17:30:22 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Colors.hpp"
#include <iostream>

Zombie::Zombie(void) : name_("") {}

Zombie::~Zombie() {
	std::cout << YELLOW << "Zombie " << this->name_ << " Destroyed" << RESET << std::endl;
}

void Zombie::announce() const {
	std::cout << RED <<"BraiiiiiiinnnzzzZ... " << this->name_ << RESET << std::endl;
}

void Zombie::setName(const std::string& name) {
	name_ = name;
}
