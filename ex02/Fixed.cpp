#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    this->fixed_num =0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    // this->fixed_num = other.getRawBits();
    //çıktının birebir aynısı olsun diye bu şekilde yapabilirim
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        // this->fixed_num = other.getRawBits();//subjectdeki kodun aynısını yapmak istersen bu olucak
        this->setRawBits(other.fixed_num);
    }
    return(*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member funciton called" << std::endl;
    return(this->fixed_num);
}

void Fixed::setRawBits(int const raw)
{
    this->fixed_num = raw;
}
Fixed::Fixed(const int i)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixed_num = (i << bits);
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixed_num = roundf(f * (1 << bits));
}

int Fixed::toInt(void) const
{
    return(this->fixed_num >> bits);
}

float Fixed::toFloat(void) const
{
    //fixed de tutulan değeri alıp bits kaydırarak ondalık hale getiriyoruz
    return((float)this->fixed_num / (1 << bits));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed_obj)
{
    //float değerini verip tam halini cout basmalı
    out << fixed_obj.toFloat();
    //out u geri döndürmeliyiz ki peş peşe işlemlerde çakışma yaşanmasın
    return out;
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed tmp;
    tmp.setRawBits(this->getRawBits() + other.getRawBits());

    return(tmp);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    float tmp (this->toFloat() * other.toFloat());
    Fixed result (tmp);

    return(result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
    if (other.getRawBits() == 0)
    {
        std::cout << "ERROR" << std::endl;
        return(Fixed(0));
    }
    float tmp = (this->toFloat() / other.toFloat());
    
    Fixed result (tmp);

    return(result);
}

Fixed Fixed::operator++(void)
{
    this->fixed_num += 1;
    return(*this);
}