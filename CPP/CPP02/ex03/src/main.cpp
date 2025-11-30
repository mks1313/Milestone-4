/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:29:39 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/30 14:52:13 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"
#include "Bsp.hpp"

static void testPoint(std::string const &label,
                      Point const &a,
                      Point const &b,
                      Point const &c,
                      Point const &p)
{
	std::cout << "=== " << label << " ===" << std::endl;
	std::cout << "A: (" << a.getX() << ", " << a.getY() << ")" << std::endl;
	std::cout << "B: (" << b.getX() << ", " << b.getY() << ")" << std::endl;
	std::cout << "C: (" << c.getX() << ", " << c.getY() << ")" << std::endl;
	std::cout << "P: (" << p.getX() << ", " << p.getY() << ")" << std::endl;

	if (bsp(a, b, c, p))
		std::cout << " -> P is INSIDE of triangle" << std::endl;
	else
		std::cout << " -> P is OUT of trinagle" << std::endl;

	std::cout << "------------------------" << std::endl;
}

int main(void)
{
	// Triángle simple
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);

	// 1) Point in
	Point p1(3.0f, 3.0f);

	// 2) Point out
	Point p2(20.0f, 20.0f);

	// 3) Point on board ( segment AB)
	Point p3(5.0f, 0.0f);

	// 4) Point on vertice (same as  A)
	Point p4(0.0f, 0.0f);

	testPoint("Case 1: point in", a, b, c, p1);
	testPoint("Case 2: point out", a, b, c, p2);
	testPoint("Case 3: point on board", a, b, c, p3);
	testPoint("Case 4: point on vertice", a, b, c, p4);

	return 0;
}
