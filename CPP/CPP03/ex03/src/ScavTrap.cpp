/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:11:47 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/11 21:23:41 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "ScavTrap.hpp"
#include "iostream"

ScavTrap::ScavTrap()
	: ClapTrap("Default")
{
	std::cout << BOLD << YELLOW << "ScavTrap Default constructor called" << RESET << std::endl;
	_hit_pts =  100;
	_energy_pts = 50;
	_attack_dmg = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << BOLD << GREEN << "ScavTrap with name " << RED << this->_name
		<< GREEN << " as a param constructor called" << RESET << std::endl;
	_hit_pts = 100;
	_energy_pts = 50;
	_attack_dmg = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << BOLD << WHITE << "Destructor called for ScavTrap " << RED << _name << RESET << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
	std::cout << BOLD << BLUE << "ScavTrap Copy constructor called" << RESET << std::endl;
	*this = copy;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &copy)
{
	std::cout << BOLD << CYAN << "ScavTrap Copy assignment operator called" << RESET << std::endl;
	if (this != &copy)
	{
		ClapTrap::operator=(copy);
	}
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << BOLD << MAGENTA << "[ATTACK]" << RESET << std::endl;
	if (cannotAct("ATTACK"))
		return;
	_energy_pts--;
	std::cout << BOLD << GREEN << "ScavTrap " << RED << _name << GREEN << " attacks "
			  << RED << target << GREEN
			  << ", causing " << WHITE << _attack_dmg << GREEN
			  << " points of damage!" << RESET << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << BOLD << YELLOW << "ScavTrap is now in Gate keeper mode." << RESET << std::endl;
}
