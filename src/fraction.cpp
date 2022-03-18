#include "fraction.h"

Fraction::Fraction(int num, int den)
    : m_num{num}, m_den{den} // <--- init-list
{
    // Here Fraction has already been initialized!
    //this->num = num;
    //(*this).den = den;
    m_val = (double) m_num / m_den;
}

/*Fraction::Fraction(int num) 
    : Fraction(num, 1) {
    // Here Fraction has already been initialized!
    //Fraction(num, 1); // Temporary object!
}

Fraction::Fraction()
: Fraction(0, 1)  {
    // Here Fraction has already been initialized!
    //Fraction(0, 1); // Temporary object!
}*/

/*Fraction::operator double() {
    return m_val;
    // or return (double) m_num / m_den;
}*/

Fraction& Fraction::operator += (const Fraction &f) {
    auto t{f.m_num*m_den};
    m_den *= f.m_den;
    m_num *= f.m_den;
    m_num += t;
    m_val = (double) m_num / m_den;
    return *this;
}

Fraction& Fraction::operator -= (const Fraction &f) {
    auto t{f.m_num*m_den};
    m_den *= f.m_den;
    m_num *= f.m_den;
    m_num -= t;
    m_val = (double) m_num / m_den;
    return *this;
}


void Fraction::set_num(int i) {
    m_num = i;
    m_val = (double) m_num / m_den;
}

void Fraction::set_den(int i) {
    if (i != 0) {
        m_num = i;
        m_val = (double) m_num / m_den;
    }
}

int Fraction::get_num() const {
    return m_num;
}

int Fraction::get_den() const {
    return m_den;
}

Fraction operator+(Fraction a, const Fraction &b) {
    return a += b;
}

Fraction operator-(Fraction a, const Fraction &b) {
    return a -= b;
}

Fraction operator-(const Fraction& a) {
    //return Fraction{-a.get_num(), a.get_den()};
    return {-a.get_num(), a.get_den()};
}