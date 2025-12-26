/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:37:01 by mmarinov          #+#    #+#             */
/*   Updated: 2025/12/26 14:44:39 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain(void);
		~Brain(void);
		Brain(Brain const &copy);
		Brain &operator=(Brain const &copy);

		void setIdea(int i, const std::string& s);
		std::string getIdea(int i) const;
};

#endif
