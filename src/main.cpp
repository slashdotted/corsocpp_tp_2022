#include <cstdint>
#include <iostream>
#include <string>

int fn(int i) {
    static int v = 0;
    ++v;
    return v+i;
}


struct Funny {
    int v;
    int operator()(int i) {
        return ++v + i;
    }
};

struct SimilarToL3 {
    int v;
    int x;
    int y;
    int operator()(){
        return v+x+y;
    };
}

int main() {
    Funny f;    
    f(2);

    int v{0};
    int x{0};
    int y{2}; 

    // A reference to v is captured   
    auto l = [&v] (int i) {
        return ++v + i;
    };
    std::cout << l(5) << '\n';
    v = 10;
    std::cout << l(5) << '\n';

    // The value of v is captured
    auto l2 = [v] (int i) {
        return v+i;
    };

    // This captures everything by value
    auto l3 = [=] () {
        return v+x+y;
    };

    SimilarToL3 sl3{v,x,y};
    sl3();

    // This captures everything by reference
    auto l4 = [&] () {
        return v+x+y;
    };

    // This captures everything by value, but x (which is capture by ref)
    auto l5 = [=,&x] () {
        return v+x+y;
    };

    // This captures everything by reference, but y (which is captured by value)
    auto l6 = [&,y] () {
        return v+x+y;
    };

}




