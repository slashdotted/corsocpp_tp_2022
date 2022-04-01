#include <iostream>
#include <stdexcept>
using namespace std;
void foo(bool b) {
    if (b) {
        throw runtime_error("Error");
    } else {
        throw out_of_range("Error");
    }
}
void bar(bool b) {
    if (b) {
        throw runtime_error("Error");
    } else {
        throw out_of_range("Error");
    }
}


int main()
{
    try {
        foo(true);
    } catch (const out_of_range& e) {
// handle out_of_range
        cout << "Handling out_of_range\n";
    } catch (const runtime_error& e) {
// handle runtime_error
        cout << "Handling runtime_error\n";
    }
// ...
    try {
        bar(true);
    } catch (const out_of_range& e) {
// handle out_of_range
        cout << "Handling out_of_range\n";
    } catch (const runtime_error& e) {
// handle runtime_error
        cout << "Handling runtime_error\n";
    }
}