/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:02:02 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/08 17:20:42 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	int N = 13;
	Zombie* horde = zombieHorde(N, "Zed");
	if (!horde) return (0);
	for(int i = 0; i < N; ++i)
		horde[i].announce();
	delete [] horde;
	return (0);
}
