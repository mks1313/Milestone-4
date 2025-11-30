/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:28:59 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/30 12:47:18 by mmarinov         ###   ########.fr       */
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

Fixed &Fixed::operator=(const Fixed &ref) {
	if (this != &ref)
		_value = ref._value;
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


//Comparisions
bool Fixed::operator>(const Fixed &ref) const { return _value > ref._value; }

bool Fixed::operator<(const Fixed &ref) const { return _value < ref._value; }

bool Fixed::operator>=(const Fixed &ref) const { return _value >= ref._value; }

bool Fixed::operator<=(const Fixed &ref) const { return _value <= ref._value; }

bool Fixed::operator==(const Fixed &ref) const { return _value == ref._value; }

bool Fixed::operator!=(const Fixed &ref) const { return _value != ref._value; }

//Arithmetics
Fixed Fixed::operator+(const Fixed &ref) const {
	Fixed tmp;
	tmp._value = this->_value + ref._value;
	return tmp;
}

Fixed Fixed::operator-(const Fixed &ref) const {
	Fixed tmp;
	tmp._value = this->_value - ref._value;
	return tmp;
}

Fixed Fixed::operator*(const Fixed &ref) const {
	Fixed tmp;
	tmp._value = (this->_value * ref._value) >> _fractionalBits;
	return tmp;
}

Fixed Fixed::operator/(const Fixed &ref) const {
	Fixed tmp;
	tmp._value = (this->_value << _fractionalBits) / ref._value;
	return tmp;
}

//Prefix
Fixed &Fixed::operator++() {
	_value++;
	return *this;
}

Fixed &Fixed::operator--() {
	_value--;
	return *this;
}

//Sufix
Fixed Fixed::operator++(int) {
	Fixed res = *this;
	++(*this);
	return res;
}

Fixed Fixed::operator--(int) {
	Fixed res = *this;
	--(*this);
	return res;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b) {
	return ( a > b ? a : b);
}

Fixed const &Fixed::min(const Fixed &a, const Fixed &b) {
	return ( a < b ? a : b);
}

std::ostream &operator<<(std::ostream &ref, Fixed const &fixed_nbr) {
	ref << fixed_nbr.toFloat();
	return ref;
}
