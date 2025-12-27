/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:58:19 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/27 16:55:36 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"

Character::Character(void) : _name("default")
{
	for (int i = 0; i < 4; i++)
		_inv[i] = NULL;
}

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inv[i] = NULL;
}

Character::Character(Character const &other) : _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inv[i])
			_inv[i] = other._inv[i]->clone();
		else
			_inv[i] = NULL;
	}
}

Character &Character::operator=(Character const &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inv[i])
				delete _inv[i];
			if (other._inv[i])
				_inv[i] = other._inv[i]->clone();
			else
				_inv[i] = NULL;
		}
	}
	return *this;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inv[i])
			delete _inv[i];
	}
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!_inv[i])
		{
			_inv[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	_inv[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && _inv[idx])
		_inv[idx]->use(target);
}
