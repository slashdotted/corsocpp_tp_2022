#include "fraction.h"
#include <iostream>

using std::cout;

void print_fraction(const Fraction& f) {
    cout << f.get_num() << "/" 
         << f.get_den() << '\n';
}

int main() {
    Fraction f;
    f.set_num(1);
    f.set_den(2);
    print_fraction(f);
}