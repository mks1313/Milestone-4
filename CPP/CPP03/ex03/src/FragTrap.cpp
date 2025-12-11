/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 22:13:27 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/11 22:44:54 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
	: ClapTrap("Default")
{
	std::cout << BOLD << YELLOW << "FragTrap Default constructor called" << RESET << std::endl;
	_hit_pts = 100;
	_energy_pts = 100;
	_attack_dmg = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << BOLD << GREEN << "FragTrap with name " << RED << this->_name
		<< GREEN << " as a param constructor called" << RESET << std::endl;
	_hit_pts = 100;
	_energy_pts = 100;
	_attack_dmg = 30;
}

FragTrap::~FragTrap()
{
	std::cout << BOLD << WHITE << "Destructor called for FragTrap " << RED << _name << RESET << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy)
{
	std::cout << BOLD << BLUE << "FragTrap Copy constructor called" << RESET << std::endl;
	*this = copy;
}

FragTrap& FragTrap::operator=(FragTrap const &copy)
{
	std::cout << BOLD << GREEN << " FragTrap Copy assignment operator called" << RESET << std::endl;
	if (this != &copy)
	{
		ClapTrap::operator=(copy);
	}
	return *this;
}

void FragTrap::highFivesGuys()
{
	std::cout << BOLD << YELLOW
	          << "FragTrap " << RED << _name << YELLOW
	          << " requests a positive high five!"
	          << RESET << std::endl;
}
