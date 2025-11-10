/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:10:30 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/10 20:30:22 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Replace.hpp"


int main(int ac, char **av) {
	if (ac !=4) {
		std::cout << "Usage: " << av[0] << "<file> <s1> <s2>" << std::endl;
		return (1);
	}
	return (replaceFile(av[1], av[2], av[3]));
}
