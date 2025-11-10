/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:04:26 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/10 21:02:47 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <fstream>
#include <iostream>

int replaceFile(const std::string& filename,
		const std::string& s1,
		const std::string& s2)
{
	if (s1.empty()) {
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return 1;
	}

	std::ifstream in(filename.c_str());
	if (!in) {
		std::cerr << "Error: cannot open " << filename << std::endl;
		return 1;
	}

	std::string content;
	char c;
	while (in >> std::noskipws >> c)
		content += c;
	in.close();

	std::ofstream out((filename + ".replace").c_str());
	if (!out) {
		std::cerr << "Error: cannot create output file" << std::endl;
		return 1;
	}

	for (std::string::size_type i = 0; i < content.size(); ++i) {
		std::string::size_type pos = content.find(s1, i);
		if (pos != std::string::npos && pos == i) {
			out << s2;
			i += s1.size() - 1;
		} else {
			out << content[i];
		}
	}
	out.close();
	return 0;
}

