#include <iostream>

void foo_byvalue(int p) {
    std::cout << "p=" << p << '\n';
    p = 89;
    std::cout << "p=" << p << '\n';
}

void foo_ptr(int* p) {
    std::cout << "*p=" << *p << '\n';
    *p = 89;
    std::cout << "*p=" << *p << '\n'; 
    p = (int*) 123;
}

void foo_byref(int& p) {
    std::cout << "p=" << p << '\n';
    p = 14;
}

void foo_byref2(const int& p) {
    std::cout << "p=" << p << '\n';
}

void swap_in_c(int* a, int* b) {
    int t{*a};
    *a = *b;
    *b = t;
}

void swap_in_cpp(int& a, int& b) {
    int t{a};
    a = b;
    b = t;
}

int bar() {
    return 42;
}

int* allocate_int(int v) {
    return new int{v};
}

int& baz(int v) {
    return v; // BAD! Return reference to temporary/stack object
}

int& baz2(int v) {
    int temp{v};
    return temp; // BAD! Return reference to temporary/stack object
}

int& baz3(int& v) {
    return v;
}

int main() {
    int a{42};
    int b{22};
    int* aptr = &a;
    int& aref{a};

    // int* zptr;
    // int& zref; // Cannot declare are reference without a "target" 
    std::cout << "a=" << a << " *aptr=" << *aptr << " aref=" << aref << '\n';
    a = 77;
    std::cout << "a=" << a << " *aptr=" << *aptr << " aref=" << aref << '\n';
    aref = 88;
    std::cout << "a=" << a << " *aptr=" << *aptr << " aref=" << aref << '\n';
    *aptr = 99;
    std::cout << "a=" << a << " *aptr=" << *aptr << " aref=" << aref << '\n';
    foo_byvalue(a);
    std::cout << "a=" << a << " *aptr=" << *aptr << " aref=" << aref << '\n';
    foo_ptr(&a);
    std::cout << "a=" << a << " *aptr=" << *aptr << " aref=" << aref << '\n';
    foo_ptr(aptr);
    std::cout << "a=" << a << " *aptr=" << *aptr << " aref=" << aref << '\n';
    foo_byref(a);
    std::cout << "a=" << a << " *aptr=" << *aptr << " aref=" << aref << '\n';
    std::cout << "a=" << a << " b=" << b << '\n';
    swap_in_cpp(a, b);
    std::cout << "a=" << a << " b=" << b << '\n';
    foo_byvalue(55);
    // foo_byref(55); // 55 is a temporary value, cannot pass by ref
    foo_byref2(55);
    // foo_byref(bar());v // bar() is a temporary value, canno pass by ref
    foo_byref2(bar()); 

    int data[] = {1,2,3,4,5};
    // Print contents
    for (const auto& x : data) {
        std::cout << x <<',';
    }
    std::cout << std::endl;
    // Iterate by copying the values
    for (auto x : data) {
        ++x;
    }
    // Print contents
    for (const auto& x : data) {
        std::cout << x <<',';
    }
    std::cout << std::endl;
    // Iterate using references
    for (auto& x : data) {
        ++x;
    }
    // Print contents
    for (const auto& x : data) {
        std::cout << x <<',';
    }
    std::cout << std::endl;



}