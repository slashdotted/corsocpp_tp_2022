#include <iostream>
#include <string>
#include <memory>

struct PSU {
    ~PSU() {
        std::cout << "Destroying PSU" << std::endl;
    }
};

double divide(double a, double b)  {
    if (b == 0) {
        throw "b is 0";
    } else if (a == 0) {
        throw 42;
    }
    return a / b;
}

void foo() noexcept
{
    auto i{new PSU};

    // SOLUTION 2: user smart pointers
    //auto i{std::make_unique<PSU>()};

    // SOLUTION 3: use the stack
    // PSU i;

    try {
        std::cout << divide(3, 0) << '\n';
    } catch (const char* msg) {
        // SOLUTION 4
        // delete i;
        std::cout << "In foo: " << msg << '\n';
        throw; // Rethrows the exception
    } catch (int v) {
         std::cout << v << '\n';
    }

    divide(0,1);
    /*
    // SOLUTION 1: Use try catch
    try {
        divide(0,1);
    } catch(...) {
        delete i;
    }*/ 
}

int main() {
    try {
        foo();
    } catch (const char* msg) {
        std::cout << "In main "<< msg <<'\n';
    } catch (...) {
        std::cout << "Houston we have a problem\n";
    }

    foo();
    std::cout << "Houston we have a problem\n";
}
