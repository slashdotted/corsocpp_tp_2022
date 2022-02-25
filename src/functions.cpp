#include <iostream>

namespace bar { // namespace declarations can spread over multiple files
    int add(int x, int y) {
        return x+y;
    }

    int sub(int x, int y) {
        return x-y;
    }

    /*void foo() {

    }*/
}