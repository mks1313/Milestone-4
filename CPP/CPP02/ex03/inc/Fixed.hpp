/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:27:54 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/30 12:33:32 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int _value;
		static const int _fractionalBits;
	
	public:
		Fixed(void);
		Fixed(const int n);
		Fixed(const float f);
		~Fixed(void);
		Fixed(Fixed const &ref);

		//Assignment
		Fixed &operator=(const Fixed &ref);

		//Comparisions
		bool operator>(const Fixed &ref) const;
		bool operator<(const Fixed &ref) const;
		bool operator>=(const Fixed &ref) const;
		bool operator<=(const Fixed &ref) const;
		bool operator==(const Fixed &ref) const;
		bool operator!=(const Fixed &ref) const;

		//Arithmetics
		Fixed operator-(const Fixed &ref) const;
		Fixed operator+(const Fixed &ref) const;
		Fixed operator*(const Fixed &ref) const;
		Fixed operator/(const Fixed &ref) const;

		//Prefix
		Fixed &operator++();
		Fixed &operator--();

		//Sufix
		Fixed operator++(int);
		Fixed operator--(int);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &ref, Fixed const &fixed_nbr);

#endif
