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

// FULL Specialization for T = std::string
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

// Template class
template<class A, class B>
struct MyPair {
    A a;
    B b;

    void info();
};

template<class A, class B>
void MyPair<A,B>::info() {
        std::cout << "MyPair<A,B>\n";
}

// Partial Specialization
template<class A>
struct MyPair<A,int> {
    A a;
    int b;

    void info() {
        std::cout << "MyPair<A,int>\n" << a << b;
    }
};

// Partial Specialization
template<class B>
struct MyPair<double,B> {
    double a;
    B b;

    void info() {
        std::cout << "MyPair<double,B>\n" << a << b;
    }
};

// Full Specialization
template<>
struct MyPair<std::string,double> {
    std::string a;
    double b;

    void info() {
        std::cout << "MyPair<std::string,double>\n" << a << b;
    }
};

/*int mymax(int a, int b) {
   return a > b ? a : b;
}

double mymax(double a, double b) {
   return a > b ? a : b;
}*/

// Template function
template<typename T>
T mymax(T a, T b) {
    return a > b ? a : b;
}

// Full specialization 
template<>
std::string mymax<std::string>(std::string a, std::string b) {
    return a > b ? a : b;
}

// Template function
template<typename T, typename U>
auto add(T a, U b) {
    return a + b;
}

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

    mymax(3.2, 4.5);

    add(3.5, 3);
    add(3, 3.5);
}

