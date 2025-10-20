/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:21:07 by mmarinov          #+#    #+#             */
/*   Updated: 2025/10/20 22:21:56 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
#include <iostream>
# include <iomanip>

class PhoneBook {
	private:
		Contact contacts_[8];
		int	count_;
		int	nextIndex_;

		std::string	promptField_(const std::string& fieldName) const;
		void	 printTableHeader_(void) const;
		void	printContactRow_(int index) const;
		std::string	formatField_(const std::string& field) const;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add(void);
		void	search(void) const;
};

#endif
