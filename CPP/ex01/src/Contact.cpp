/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:17:51 by mmarinov          #+#    #+#             */
/*   Updated: 2025/10/20 23:08:42 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}
Contact::~Contact(void) {}

//Setters
void	Contact::setFirstName(const std::string& fn) { firstName_ = fn; }
void	Contact::setLastName(const std::string& ln) { lastName_ = ln; }
void	Contact::setNickname(const std::string& nn) { nickname_ = nn; }
void	Contact::setPhoneNumber(const std::string& pn) { phoneNumber_ = pn; }
void	Contact::setDarkestSecret(const std::string& ds) { darkestSecret_ = ds; }

//Getter
std::string Contact::getFirstName(void) const { return firstName_;}
std::string Contact::getLastName(void) const { return lastName_; }
std::string Contact::getNickname(void) const { return nickname_; }
std::string Contact::getPhoneNumber(void) const { return phoneNumber_; }
std::string Contact::getDarkestSecret(void) const { return darkestSecret_; }

