/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:02:02 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/08 13:43:55 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string name);

void randomChump(std::string name);

int	main(void) {
	Zombie *z = newZombie("Mks13");
	z->anounce();
	randomChump("Bro13");
	delete(z);
	return (0);
}
