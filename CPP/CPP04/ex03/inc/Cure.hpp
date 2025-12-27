/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 21:20:49 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/26 21:30:57 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &other);
		~Cure(void);
		Cure &operator=(const Cure &other);

		AMateria *clone() const;
		virtual void use(ICharacter &target) const;
};

#endif
