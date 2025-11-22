/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:14:31 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/22 17:21:47 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void):_value(0) {
	std::cout << "Default constructor called " << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called " << std::endl;
}

Fixed::Fixed(Fixed const &copy) {
	std::cout << "Copy constructor called " << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy) {
	std::cout << "Copy assignment operator called " << std::endl;
	this->_value = copy._value;
	return (*this);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called " << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

Fixed::Fixed(const int value) : _value(value << _fractionalBits) {
	std::cout << "Int constructor called " << std::endl;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionalBits))) {
	std::cout << "Float constructor called " << std::endl;
}

int Fixed::toInt() const { return _value >> _fractionalBits; }

float Fixed::toFloat() const { return (float)_value / (1 << _fractionalBits); }

std::ostream &operator<<(std::ostream &str, Fixed const &fixed_nbr) { return str << fixed_nbr.toFloat(); }
