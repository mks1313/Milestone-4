/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 21:43:53 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/26 21:57:26 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include <string>

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _inv[4];

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & other);
		MateriaSource &operator=(MateriaSource const & other);
		virtual ~MateriaSource(void);

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif
