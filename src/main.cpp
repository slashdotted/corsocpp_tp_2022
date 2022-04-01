#include <iostream>
#include <string>
#include <memory>

class A {
public:
    int i;
};

class B : A  { // if we forget "public" it is private derivation by default

};

struct C : A  { // if we forget "public" it is public derivation by default

};

void foo(const A& a) {

}

int main() {
  /*  A objA;
    objA.i = 42;

    B objB;
    objB.i = 5;
    foo(obj);
    foo(objB);

    C objC;
    objC.i = 5;
    foo(objA);
    foo(objC);*/
}
