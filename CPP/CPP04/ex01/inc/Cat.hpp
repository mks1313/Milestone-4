/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:26:37 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/26 15:21:24 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* brain;

	public:
		Cat(void);
		~Cat(void);
		Cat(Cat const &copy);
		Cat &operator=(Cat const &copy);

		Brain* getBrain();
		const Brain* getBrain() const;
		void makeSound(void) const;
};

#endif
