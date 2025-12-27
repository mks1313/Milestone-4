/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 20:15:30 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/27 16:46:20 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(void) : type("") {}

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(AMateria const & other) : type(other.type) {}

AMateria &AMateria::operator=(AMateria const & other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

AMateria::~AMateria(void) {}

std::string const & AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter& target) const
{
	(void)target;
}

