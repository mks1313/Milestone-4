/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:08:55 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/08 16:48:01 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
	private:
		std::string name_;
	public:
		Zombie(std::string name);
		Zombie(void);
		~Zombie(void);
	
	void setName(const std::string& name);
	void announce(void) const;
};

Zombie* zombieHorde(int N, std::string name);

#endif
