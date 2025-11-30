/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:57:56 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/30 14:54:09 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bsp.hpp"

static Fixed absFixed(Fixed x)
{
	if (x < Fixed(0))
		return x * Fixed(-1);
	return x;
}

// Área oriented of  triángle (a, b, c)
static Fixed area(Point const a, Point const b, Point const c)
{
	// Fórmula : (1/2) * |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)|
	return ((a.getX() * (b.getY() - c.getY()))
		  + (b.getX() * (c.getY() - a.getY()))
		  + (c.getX() * (a.getY() - b.getY()))) / Fixed(2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed abcArea = absFixed(area(a, b, c));
	Fixed pabArea = absFixed(area(point, a, b));
	Fixed pbcArea = absFixed(area(point, b, c));
	Fixed pcaArea = absFixed(area(point, c, a));

	// Punto out if: suma of subareas != total area
	if (abcArea != pabArea + pbcArea + pcaArea)
		return false;

	// inside: noOne of subareas is 0
	if (pabArea == Fixed(0) || pbcArea == Fixed(0) || pcaArea == Fixed(0))
		return false;

	return true;
}
