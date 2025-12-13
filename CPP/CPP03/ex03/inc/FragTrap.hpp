/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:27:54 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/13 16:31:25 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const std::string& name);
		~FragTrap(void);
		FragTrap(FragTrap const &copy);
		FragTrap &operator=(FragTrap const &copy);

		void highFivesGuys(void);
};

#endif
