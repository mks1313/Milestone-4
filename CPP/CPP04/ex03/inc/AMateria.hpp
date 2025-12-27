/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 19:14:01 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/26 22:03:24 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string type;

	public:
		AMateria(void);
		AMateria(AMateria const & other);
		AMateria &operator=(AMateria const & other);
		AMateria(std::string const & type);
		virtual ~AMateria(void);

		std::string const & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) const;
		
};

#endif
