/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:37:15 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/08 19:18:46 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "String address:    " << &str << std::endl;
	std::cout << "Pointer address:   " << stringPTR << std::endl;
	std::cout << "Reference address: " << &stringREF << std::endl;

	std::cout << "String value:      " << str << std::endl;
	std::cout << "Pointer value:     " << *stringPTR << std::endl;
	std::cout << "Reference value:   " << stringREF << std::endl;
	return (0);
}

