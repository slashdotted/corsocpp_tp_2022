#include <cstdint>
#include <iostream>
#include <string>
#include "mylist.h"

template <typename A, typename B = int>
struct Pair {
    A a;
    B b;
};

template <typename A = double>
struct Vector {
    A x;
    A y;
    A z;
};


// Size is a non-type template parameter
template <typename A, int Size = 1000>
struct MyData {
    int get() {
        return Size;
    }
    A m_a;
};

// Generic class
template <typename T>
struct Foo {
    void printLength(T x) {
        std::cout << sizeof(x) << ":" << x << '\n';
    }
};

// Specialization for T = std::string
template <>
struct Foo<std::string> {
    void printLength(std::string x) {
        std::cout << x.size() << ":" << x << '\n';
    }
};

// Specialization for T*
template <typename T>
struct Foo<T*> {
    void printLength(T* x) {
        std::cout << sizeof(*x) << ":" << *x << '\n';
    }
};


int main() {
    MyList<int> m1{10};
    MyList<double> m2{20};

    m1[0] = 52;
    std::cout << m1[0] << '\n';

    Pair<int,double> x{5,3.14};
    Pair<int> y{6,7};
    Vector<double> v{1.2,3.1,5.1};
    Vector<> v2{1.2,3.1,5.1};

    MyData<double, 1000> md;
    MyData<double> md1;

    Foo<int> f;
    f.printLength(7);
    Foo<std::string> g;
    g.printLength("my string");
    Foo<int*> h;
    int u{3};
    h.printLength(&u);

}

