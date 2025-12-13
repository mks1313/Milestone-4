/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:27:09 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/13 16:31:15 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class ScavTrap : public ClapTrap
{

	public:
		ScavTrap(void);
		ScavTrap(const std::string& name);
		~ScavTrap(void);
		ScavTrap(ScavTrap const &copy);
		ScavTrap &operator=(ScavTrap const &copy);

		void attack(const std::string& target);
		void guardGate();
};

#endif
