#include <iostream>
#include <string>
#include "functions.h"

// void say(); // forward declaration
void say(int x=0); // Default values go into the declaration, not the definition

namespace bar { // namespace declaration
    void foo() {
         std::cout << "This is bar::foo()" << std::endl;
    }

    void baz() {
        std::cout << "This is bar::baz()" << std::endl;
    }
}

// hierarchical namespace declarations are also possible
namespace supsi {
    namespace bla {
        int add(int x, int y) {
            return 0;
        }
    }
}

void foo() {
    say();
}

// definition / implementation
/*void say() {
    //std::cout << "This is say(0)" << std::endl;
    say(0);
}*/

void say(int x) {
    std::cout << "This is say(" << x << ")" << std::endl;
}

int mul(int x = 0, int y = 1, int z = 1) {
    return x*y*z;
}

// Will be ambiguous if we call mul()
/*int mul() {
    return 0;
}*/

void myfun(int x, double y) {
}

void myfun(double x, int y) {
}

auto somefun() {
    return 3;
}

void fromjava() {
    //auto* mystr = new std::string{"Course"}; // mystr is allocated on the HEAP
    std::string mystr{"Course"}; // mystr is on the STACK
    //std::string s = new std::string{"blabla"}; // Not correct: tries to assign a pointer to a value
    std::string t; // t is a string value!
    std::cout << t << '\n';
    //delete mystr; // WE HAVE TO FREE THE MEMORY (no GC)
}

namespace fn = supsi::bla; // Create an alias for supsi::bla -> we can use fn instead of supsi::bla
using std::endl; // Import one 'symbol' in the global namespace
// using namespace bar; // Import all the namespace 'bar' inside the global namespace ---> BAD PRACTICE

int main()
{
    std::cout << "Hello world" << endl;
    std::cout << bar::add(5, 6) << endl;
    std::cout << supsi::bla::add(5, 6) << endl;
    std::cout << fn::add(5,6) << endl;
    say();
    say(5);
    mul(3,6);
    mul(3,4,5);
    mul(3);
    //mul();
    bar::sub(7);
    // bar::foo(); // Ambiguous: there are multiple foo in the bar namespace
    myfun(3.4, 4);
    myfun(4,3.14);
    // myfun(2,3); // Ambiguous: either myfun(double,int) or myfun(int,double) match this call
    myfun(2,double(3)); // or myfun(2,3.0);


    std::string message = "Héllo world";
    std::cout << message << " - " << message.length() << '\n';
    message += "ciao";
    std::string a = "A";
    std::string b = "B";
    if (a == b) {

    } else if (a == "C") {

    }
    std::cout << "First:" << message[0] << '\n';

    int x = 0; // C-style declaration/initialization
    int y(8); // C++ (old-style)
    int z{3}; // Preferred way in C++11
    int k = {7}; // ...

    int d = 3.14;
    // int s{3.14}; // Error!
    std::string salute{"Hello moon"};

    auto pi{3.14};
    auto result{mul(1,2,3)};

    auto mystr{"Hello mars"}; // mystr is of type const char*
    std::string mystring{"Hello mars"};

    int myarr[] {1,2,3,4};
    for (int x : myarr) {
        std::cout << x << '\n';
    }
    for (auto y : myarr) {
        std::cout <<y << '\n';
    }
    for (auto z : {9,8,7,6,5,4,3,2,1}) {
        std::cout << z << '\n';
    }

    {
        auto* p = new int{42};
        int* q = nullptr; 
        if (!q) {

        }
        delete p;
    }

}
