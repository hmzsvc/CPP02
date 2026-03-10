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
    // burada sayıyı 8 bit kaydırarak 2 üzeri 8 ile çarpıp float değer için yer açıyoruz
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixed_num = roundf(f * (1 << bits));
    //bit kaydırma olmayacağı için 256 ile çarpıp hassasiyeti kaybetmemek için roundf ile yuvarla
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
    //out stream kütüp ait bir fonk << ile fixed nesnesinedn bir değer alması gerekiyor 
    //ama bunu tanımıyor biz ona bu durumda ne yacapağını söylüyoruz
    out << fixed_obj.toFloat(); // neyi out a göndereceğini biz belirliyoruz 
    return(out); //out a return değeri atıyoruz ve 
    //return edip out a gönderiyorki peş peşe çalıştıırp düzenleyelim 
}