/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 19:54:16 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/11 19:17:33 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "Colors.hpp"
#include <iostream>

ClapTrap::ClapTrap() 
	: _name("Default"), _hit_pts(10), _energy_pts(10), _attack_dmg(0)
{
	std::cout << BOLD << YELLOW << "ClapTrap Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hit_pts(10), _energy_pts(10), _attack_dmg(0)
{
	std::cout << BOLD << GREEN << "ClapTrap with name " <<  RED << this->_name
		<< GREEN << " as a param constructor called" << RESET << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << BOLD << WHITE << "Destructor called for ClapTrap " << RED << _name << RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
	: _name(copy._name),
	_hit_pts(copy._hit_pts),
	_energy_pts(copy._energy_pts),
	_attack_dmg(copy._attack_dmg)
{
	std::cout << BOLD << BLUE << "ClapTrap Copy constructor called" << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &copy)
{
	std::cout << BOLD << CYAN << "ClapTrap Copy assignment operator called" << RESET << std::endl;
	if (this != &copy)
	{
		_name = copy._name;
		_hit_pts = copy._hit_pts;
		_energy_pts = copy._energy_pts;
		_attack_dmg = copy._attack_dmg;
	}
	return *this;
}

bool ClapTrap::cannotAct(const std::string& action) const
{
	if (_hit_pts == 0)
	{
		std::cout << BOLD << RED << "ClapTrap " << YELLOW << _name << RED
			<< " cannot " << CYAN << action << RED
			<< " because it has no hit points (HP)." 
			<< RESET << std::endl;
		return true;
	}

	if (_energy_pts == 0)
	{
		std::cout << BOLD << RED << "ClapTrap " << YELLOW << _name << RED
			<< " cannot " << CYAN << action << RED
			<< " because it has no energy points left."
			<< RESET << std::endl;
		return true;
	}

	return false;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << BOLD << MAGENTA << "[ATTACK]" << RESET << std::endl;
	if (cannotAct("ATTACK"))
		return;

	_energy_pts--;
	std::cout << BOLD << GREEN << "ClapTrap " << RED << _name << GREEN << " attacks "
					   << RED <<  target << GREEN
					   << ", causing " << WHITE << _attack_dmg << GREEN
					   << " pts of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << BOLD << CYAN << "[TAKEDAMAGE]" << RESET << std::endl;

	if (_hit_pts == 0)
	{
		std::cout << RED << _name << GREEN
		          << " is already at 0 HP" << RESET << std::endl;
		return;
	}
	if (amount >= _hit_pts)
		_hit_pts = 0;
	else
		_hit_pts -= amount;

	std::cout << BOLD << RED << _name << GREEN << " received " << WHITE
	          << amount << GREEN << " damage and is left with " << WHITE
	          << _hit_pts << GREEN << " HP" << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << BOLD << CYAN << "[BEREPAIRED]" << RESET << std::endl;
	if (cannotAct("REPAIR ITSELF"))
		return;
	_energy_pts--;
	_hit_pts += amount;
	std::cout << BOLD << RED << _name << GREEN << " has been repaired with "
		<< WHITE << amount << GREEN << " HP " << GREEN << " and has left "
		<< WHITE << _energy_pts << GREEN << " HP " << RESET << std::endl;
}

void ClapTrap::print_msg() const
{
	std::cout << BOLD << GREEN << "[ClapTrap status]\n" << RESET;
	std::cout << CYAN << "name   : " << YELLOW << _name << RESET << '\n';
	std::cout << CYAN << "hit    : " << YELLOW <<  _hit_pts << RESET  << '\n';
	std::cout << CYAN << "energy : " << YELLOW << _energy_pts << RESET << '\n';
	std::cout << CYAN << "attack : " << YELLOW << _attack_dmg << RESET << '\n';
}
