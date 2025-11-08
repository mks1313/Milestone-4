/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:04:36 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/08 13:54:18 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Colors.hpp"

Zombie::Zombie(std::string name) {
	this->name_ = name;
	std::cout << GREEN << "Zombie 🧟" << this->name_ << " Created" << RESET << std::endl;
}

Zombie::~Zombie() {
	std::cout << YELLOW << "Zombie " << this->name_ << " Destroyed⚰️ ⚰️ ⚰️" << RESET << std::endl;
}

void Zombie::anounce() {
	std::cout << RED <<"BraiiiiiiinnnzzzZ...🧠 " << this->name_ << RESET << std::endl;
}
