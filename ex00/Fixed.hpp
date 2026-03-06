#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
//eğer iki Fixed nesnesi arasında = işareti görürsen,
// git benim yazdığım bu özel fonksiyonu çalıştır.
class Fixed
{
    private:
        int raw;
        static const int bits = 8;
    public:
        Fixed();
        Fixed(const Fixed &other); //copy constructor=fixed b(a) a zaten varolanı b ye copyalamak ref gibi
        Fixed &operator=(const Fixed &other); // copy assigment operatör= kopyalama atama operatörü
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif