#include <iostream>
using std::cout, std::endl;

class Base {
public:
    virtual void f(double x)
    {
        cout << "Base::f(double x)" << endl;
    }
};

class Derived : public Base {
public:
    using Base::f;

    void f(int x)
    {
        cout << "Derived::f(int x)" << endl;
    }

    /*void f(double x) override {
        Base::f(x);
    }*/
};

int main()
{
    Derived e;
    // e.Base::f(3.2);
    e.f(3);
}