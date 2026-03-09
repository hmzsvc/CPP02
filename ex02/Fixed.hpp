#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int fixed_num;
        static const int bits = 8;
    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();

        Fixed(const int i);
        Fixed(const float f);

        float toFloat(void) const;
        int toInt(void) const;

        int getRawBits(void) const;
        void setRawBits(int const raw);

        bool Fixed::operator>(const Fixed &other) const;
        bool Fixed::operator<(const Fixed &other) const;
        bool Fixed::operator>=(const Fixed &other) const;
        bool Fixed::operator<=(const Fixed &other) const;
        bool Fixed::operator==(const Fixed &other) const;
        bool Fixed::operator!=(const Fixed &other) const;
        
        Fixed Fixed::operator+(const Fixed &other) const;
        Fixed Fixed::operator*(const Fixed &other) const;
        Fixed Fixed::operator/(const Fixed &other) const;
        Fixed Fixed::operator++(void);

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed_obj);

#endif