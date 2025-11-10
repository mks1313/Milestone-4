/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 21:22:44 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/10 22:43:47 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av) {
	Harl h;
	if (ac != 2) {
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		return 1;
	}
	h.complain(av[1]);
	return 0;
}
