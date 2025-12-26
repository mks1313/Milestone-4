/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:23:29 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/26 17:07:18 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
	protected:
		std::string type;

	public:
		Animal(void);
		Animal(const std::string& type);
		virtual ~Animal(void);
		Animal(Animal const &copy);
		Animal &operator=(Animal const &copy);

		void setType(const std::string& type);
		std::string getType(void) const;

		virtual void makeSound(void) const = 0;
};

#endif
