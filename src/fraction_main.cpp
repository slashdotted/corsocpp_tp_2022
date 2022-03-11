#include "fraction.h"
#include <iostream>

using std::cout;

void print_fraction(const Fraction& f) {
    cout << f.get_num() << "/" 
         << f.get_den() << "="
         << f.m_val <<  '\n';
}

std::ostream& operator<<(std::ostream& o , const Fraction& f) {
     cout << f.get_num() << "/" 
         << f.get_den() << "="
         << f.m_val <<  '\n';
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



int main() {
    Fraction f;
    f.set_num(1);
    f.set_den(2);
    print_fraction(f);
    cout << f << " -" << f;
    
    Fraction *f2{new Fraction};
    Fraction f3 = f+*f2;

    // ...

    //f += *f2; // f = f+f2


    delete f2;
}