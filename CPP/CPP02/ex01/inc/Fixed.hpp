/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:15:51 by mmarinov          #+#    #+#             */
/*   Updated: 2025/11/22 14:41:33 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int		_value;
		static const int	_fractionalBits;
	
	public:
		Fixed(void);
		Fixed(const int n);
		Fixed(const float f);
		~Fixed(void);
		Fixed(Fixed const &copy);
		Fixed &operator=(Fixed const &copy);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif
