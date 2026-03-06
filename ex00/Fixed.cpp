#include "Fixed.hpp"

Fixed::Fixed()
{
    this->raw =0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    // this->raw = other.getRawBits();
    //çıktının birebir aynısı olsun diye bu şekilde yapabilirim
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->raw = other.getRawBits();//subjectdeki kodun aynısını yapmak istersen bu olucak
        // this->setRawBits(other.raw);
    }
    return(*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member funciton called" << std::endl;
    return(this->raw);
}

void Fixed::setRawBits(int const raw)
{
    this->raw = raw;
}