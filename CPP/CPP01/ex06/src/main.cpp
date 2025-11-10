/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 22:41:58 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/10 22:46:37 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

static int level_index(const std::string& s) {
	const std::string L[4] = {"DEBUG","INFO","WARNING","ERROR"};
	for (int i = 0; i < 4; ++i) if (L[i] == s) return i;
	return -1;
}

int main(int ac, char **av) {
	Harl h;
	if (ac != 2) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 1;
	}
	int idx = level_index(av[1]);
	switch (idx) {
		case 0: h.complain("DEBUG");
		case 1: h.complain("INFO");
		case 2: h.complain("WARNING");
		case 3: h.complain("ERROR"); break;
		default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return 0;
}
