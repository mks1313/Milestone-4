/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:28:59 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/22 20:04:42 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void):_value(0) {}

Fixed::~Fixed(void) {}

Fixed::Fixed(Fixed const &copy) {
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy) {
	this->_value = copy._value;
	return (*this);
}

int Fixed::getRawBits(void) const {
	return (this->_value);
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

Fixed::Fixed(const int value) : _value(value << _fractionalBits) {}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionalBits))) {}

int Fixed::toInt() const { return _value >> _fractionalBits; }

float Fixed::toFloat() const { return (float)_value / (1 << _fractionalBits); }

std::ostream &operator<<(std::ostream &str, Fixed const &fixed_nbr) { return str << fixed_nbr.toFloat(); }


