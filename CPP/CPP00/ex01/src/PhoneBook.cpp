/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 22:06:53 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/01 11:01:15 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Colors.hpp"

static std::string trim(const std::string& s) {
	size_t a = s.find_first_not_of(" \t\r\n");
	size_t b = s.find_last_not_of(" \t\r\n");
	return (a == std::string::npos) ? "" : s.substr(a, b - a + 1);
}

static bool hasLetter(const std::string& s) {
	for (size_t i = 0; i < s.length(); i++) {
		if (std::isalpha(s[i]))
			return true;
	}
	return false;
}

static bool isPhoneNumber(const std::string& s) {
	if (s.empty()) return false;
	size_t i = (s[0] == '+') ? 1 : 0;
	if (i == s.size()) return false;
	return s.find_first_not_of("0123456789", i) == std::string::npos;
}

PhoneBook::PhoneBook(void) : count_(0), nextIndex_(0) {}

PhoneBook::~PhoneBook(void) {}

std::string PhoneBook::promptField_(const std::string& fieldName) const {
	std::string s;
	while (true) {
		std::cout << fieldName << ": " << RESET;
		if (!std::getline(std::cin, s)) return "";
		s = trim(s);
		if (!s.empty()) return s;
		std::cout << RED << "⚠️  Empty field. Try again." << RESET << std::endl;
	}
}

std::string PhoneBook::formatField_(const std::string& field) const {
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}

void PhoneBook::printTableHeader_(void) const {
	std::cout << BOLD << CYAN
	          << std::setw(10) << "INDEX" << "|"
	          << std::setw(10) << "FIRST" << "|"
	          << std::setw(10) << "LAST"  << "|"
	          << std::setw(10) << "NICK"  << RESET << std::endl;
	std::cout << CYAN << std::string(43, '-') << RESET << std::endl;
}

void PhoneBook::printContactRow_(int i) const {
	const Contact& c = contacts_[i];
	std::cout << YELLOW
	          << std::setw(10) << i << "|"
	          << std::setw(10) << formatField_(c.getFirstName()) << "|"
	          << std::setw(10) << formatField_(c.getLastName())  << "|"
	          << std::setw(10) << formatField_(c.getNickname())
	          << RESET << "\n";
}

void PhoneBook::add(void) {
	std::cout << CYAN << "➕ Adding a new contact..." << RESET << std::endl;

	std::string fn;
	while (true) {
		fn = promptField_(MAGENTA "First name" RESET);
		if (fn.empty()) return;
		if (hasLetter(fn)) break;
		std::cout << RED << "⚠️  First name must contain at least one letter."
		          << RESET << std::endl;
	}

	std::string ln;
	while (true) {
		ln = promptField_(MAGENTA "Last name" RESET);
		if (ln.empty()) return;
		if (hasLetter(ln)) break;
		std::cout << RED << "⚠️  Last name must contain at least one letter."
		          << RESET << std::endl;
	}

	std::string nn = promptField_(MAGENTA "Nickname" RESET);
	if (nn.empty()) return;

	std::string pn;
	while (true) {
		pn = promptField_(MAGENTA "Phone number" RESET);
		if (pn.empty()) return;
		if (isPhoneNumber(pn)) break;
		std::cout << RED << "⚠️  Invalid number. Use only digits (with optional '+' at the beginning)."
		          << RESET << std::endl;
	}

	std::string ds = promptField_(MAGENTA "Darkest secret" RESET);
	if (ds.empty()) return;

	Contact& slot = contacts_[nextIndex_];
	slot.setFirstName(fn);
	slot.setLastName(ln);
	slot.setNickname(nn);
	slot.setPhoneNumber(pn);
	slot.setDarkestSecret(ds);

	if (count_ < 8) count_++;
	nextIndex_ = (nextIndex_ + 1) % 8;

	std::cout << GREEN << "✅ Contact saved successfully!" << RESET << std::endl;
}

void PhoneBook::search(void) const {
	if (count_ == 0) {
		std::cout << YELLOW << "PhoneBook is empty." << RESET << "\n";
		return;
	}

	std::cout << CYAN << "🔍 Searching contacts..." << RESET << "\n\n";

	printTableHeader_();
	for (int i = 0; i < count_; i++)
		printContactRow_(i);
	std::cout << std::endl;

	std::string input;
	int index;
	while (true) {
		std::cout << MAGENTA << "Enter index to view details (or press Enter to cancel): " << RESET;
		if (!std::getline(std::cin, input))
			return;
		input = trim(input);
		if (input.empty())
			return;

		if (input.length() == 1 && input[0] >= '0' && input[0] <= '7') {
			index = input[0] - '0';
			if (index < count_)
				break;
		}
		std::cout << RED << "⚠️  Invalid index. Enter a number between 0 and "
		          << (count_ - 1) << "." << RESET << std::endl;
	}

	const Contact& c = contacts_[index];
	std::cout << GREEN << "\n📇 Contact Details:\n" << RESET;
	std::cout << CYAN << "─────────────────────────────────────\n" << RESET;
	std::cout << BOLD << "First name:      " << RESET << c.getFirstName() << "\n";
	std::cout << BOLD << "Last name:       " << RESET << c.getLastName() << "\n";
	std::cout << BOLD << "Nickname:        " << RESET << c.getNickname() << "\n";
	std::cout << BOLD << "Phone number:    " << RESET << c.getPhoneNumber() << "\n";
	std::cout << BOLD << "Darkest secret:  " << RESET << c.getDarkestSecret() << "\n";
	std::cout << CYAN << "─────────────────────────────────────\n" << RESET << "\n";
}
