/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:58:35 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/30 14:47:30 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() {}
Point::Point(const float x, const float y) : _x(x), _y(y) {}
Point::Point(const Point &tmp) : _x(tmp._x), _y(tmp._y) {}
Point::~Point() {}

Point &Point::operator=(const Point &tmp)
{
	(void)tmp;
	return *this;
}

Fixed const &Point::getX() const { return _x; }
Fixed const &Point::getY() const { return _y; }

void Point::getXY() const
{
	std::cout << "x: " << _x.toFloat() << ", y: " << _y.toFloat() << std::endl;
	std::cout << "------------" << std::endl;
}
