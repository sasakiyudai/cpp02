#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int inte);
		Fixed(const float floa);
		~Fixed();

		Fixed& operator=(const Fixed &other);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
	private:
		int value;
		static const int bits = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif
