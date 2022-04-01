#include <iostream>
using std::cout, std::endl;

class Base {
public:
    ~Base() {
        cout << "Destroying Base" << endl;
    }
};

class Derived : public Base {
public:
    Derived() : m_intptr { new int } {};
    ~Derived() {
        cout << "Destroying Derived" << endl;
        delete m_intptr;
    }
private:
    int* m_intptr;
};

class Manager {
public:
    Manager() : m_resource{nullptr} {};
    ~Manager() {
        delete m_resource;
    }
    void resource(Base* r) {
        delete m_resource;
        m_resource = r;
    }
private:
    Base* m_resource;
};

int main() {
    Manager g;
    Derived* pd = new Derived();
    g.resource(pd);
}