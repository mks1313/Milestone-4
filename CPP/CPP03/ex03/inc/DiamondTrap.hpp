/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 22:50:10 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/13 16:48:24 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;

	public:
		DiamondTrap(void);
		DiamondTrap(const std::string& name);
		~DiamondTrap(void);
		DiamondTrap &operator=(DiamondTrap const &copy);
		DiamondTrap(DiamondTrap const &copy);

		using ScavTrap::attack;

		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void print_msg() const;

		void whoAmI(void);
};

#endif
