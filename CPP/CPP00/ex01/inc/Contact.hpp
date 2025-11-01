/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:20:54 by mmarinov          #+#    #+#             */
/*   Updated: 2025/10/20 22:18:50 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	private:
		std::string firstName_;
		std::string lastName_;
		std::string nickname_;
		std::string phoneNumber_;
		std::string darkestSecret_;
	public:
		Contact(void);
		~Contact(void);

		//Setter
		void	setFirstName(const std::string& fn);
		void	setLastName(const std::string& ln);
		void	setNickname(const std::string& nn);
		void	setPhoneNumber(const std::string& pn);
		void	setDarkestSecret(const std::string& ds);

		//Getter
		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickname(void) const;
		std::string getPhoneNumber(void) const;
		std::string getDarkestSecret(void) const;
};

#endif
