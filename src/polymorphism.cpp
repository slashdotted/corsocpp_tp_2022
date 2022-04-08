#include <iostream>
using std::cout, std::endl;

class Base {
public:
    void bar() {
        cout << "\tBase::bar()" << endl;
    }
};

class Derived : public Base {
public:
    virtual void bar() {
        cout << "\tDerived::bar()" << endl;
    }
};

class DoubleDerived : public Derived {
public:
    void bar() override {
        cout << "\tDoubleDerived::bar()" << endl;
    }
};

int main()
{
    DoubleDerived sd;
    Base& bd {sd};
    Derived& dd {sd};
    bd.bar();
    dd.bar();
}