#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

// A fraction type c++
class Fraction {
    // "Forward declare" functions or classes as friends
    // that will have access to private/protected fields/methods
    friend void print_fraction(const Fraction& f);
    friend class Logger;
    friend std::ostream& operator<<(std::ostream& o , const Fraction& f);
public: // implicit for struct, no need to write it
    Fraction(int num = 0, int den = 1);
    // Any constructor which takes/accepts one parameter
    // is a conversion constructor

   // Fraction(int num);
   // Fraction();

    Fraction& operator += (const Fraction &f);
    Fraction& operator -= (const Fraction &f);

    // Implementing + as a method prevents 
    // int + Fraction 
    /*Fraction operator+(const Fraction &b) {
        Fraction t{*this};
        return t += b;
    }*/

    // operator double();

    // Prefix (++f)
    Fraction& operator++() {
        return *this += 1;
    }

    // Prefix (--f)
    Fraction& operator--() {
        return *this -= 1;
    }

    // Postfix (f++)
    Fraction operator++(int) {
        Fraction x{*this}; // Fraction x= *this;
        *this += 1;
        return x;
    }

    // Postfix (f--)
    Fraction operator--(int) {
        Fraction x{*this}; // Fraction x= *this;
        *this -= 1;
        return x;
    }

    void set_num(int i);
    void set_den(int i);
    // This a getter
    // Getter is not supposed to modify the object
    // THEREFORE we declare it as a const method
    int get_num() const;
    int get_den() const;

// protected:
private:
    int m_num, m_den;
    double m_val;
};

Fraction operator+(Fraction a, const Fraction &b);
Fraction operator-(Fraction a, const Fraction &b);
Fraction operator-(const Fraction& a);

#endif

