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

void foo(const Fraction& o) {

}

struct Storage {
    explicit Storage(int size) {}

};

void bar(const Storage& s) {

}

void baz(double d) {

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
    int i{7};
    int j{13};
    int z{i + j};
    int z1{j + i};

    //f += *f2; // f = f+f2
    Fraction f4 = 7;
    f3 = 7; // f3 = Fraction{7};
    Fraction f5{7};
    foo(7);

    //baz(f3);
    //double m{f3};
    //m = *f2;

    // bar(10); // Cannot automatically convert int to Storage
                // because Storage(int) is explicit
    bar(Storage{10});

    Fraction f6 = f + i; // f.operator+(i) -> f.operator+(Fraction{i})
    //Fraction f7 = i + f; // i.operator+(f)


    // f.operator+(Fraction{i})
    // double(f) + i



    Fraction f7 = i + f;

    delete f2;
}