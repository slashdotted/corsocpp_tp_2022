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
   // Fraction(int num);
   // Fraction();

    Fraction& operator += (const Fraction &f);
    Fraction& operator -= (const Fraction &f);

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

#endif

