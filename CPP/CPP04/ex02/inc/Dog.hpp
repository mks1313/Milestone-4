/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:28:05 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/26 15:21:38 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* brain;

	public:
		Dog(void);
		~Dog(void);
		Dog(Dog const &copy);
		Dog &operator=(Dog const &copy);

		Brain* getBrain();
		const Brain* getBrain() const;
		void makeSound(void) const;
};

#endif
