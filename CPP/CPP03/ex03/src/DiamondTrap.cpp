/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 22:54:05 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/13 17:02:35 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "Colors.hpp"
#include <iostream>

void DiamondTrap::print_msg() const { ScavTrap::print_msg(); }
void DiamondTrap::takeDamage(unsigned int a) { ScavTrap::takeDamage(a); }
void DiamondTrap::beRepaired(unsigned int a) { ScavTrap::beRepaired(a); }

DiamondTrap::DiamondTrap()
	: ScavTrap("Default_clap_name"),
	FragTrap("Default_clap_name"),
	_name("Default")
{
	std::cout << BOLD << GREEN << "DiamondTrap Default constructor called" << RESET << std::endl;
	ScavTrap::_hit_pts = 100;
	ScavTrap::_energy_pts = 50;
	ScavTrap::_attack_dmg = 30;

}

DiamondTrap::DiamondTrap(const std::string& name)
	: ScavTrap(name + "_clap_name"),
	FragTrap(name + "_clap_name"),
	_name(name)
{
	std::cout << BOLD << GREEN << "DiamondTrap with name " << RED << this->_name
		<< GREEN << " as a param constructor called" << RESET << std::endl;
	ScavTrap::_hit_pts = 100;
	ScavTrap::_energy_pts = 50;
	ScavTrap::_attack_dmg = 30;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << BOLD << WHITE << "Destructor called for DiamondTrap " << RED << _name
		<< RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
	: ScavTrap(copy),
	FragTrap(copy),
	_name(copy._name)
{
	std::cout << BOLD << GREEN
		<< "DiamondTrap Copy constructor called"
		<< RESET << std::endl;
	*this = copy;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const &copy)
{
	std::cout << BOLD << GREEN << "DiamondTrap Copy assignment operator called" 
		<< RESET << std::endl;
	if (this != &copy)
	{
		ScavTrap::operator=(copy);
		FragTrap::operator=(copy);
		_name = copy._name;
		ScavTrap::_hit_pts = copy.ScavTrap::_hit_pts;
		ScavTrap::_energy_pts = copy.ScavTrap::_energy_pts;
		ScavTrap::_attack_dmg = copy.ScavTrap::_attack_dmg;

	}
	return *this;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << _name << "\n";
	std::cout << "ClapTrap name: " << ScavTrap::_name << "\n";
}
