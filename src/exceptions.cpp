#include <iostream>
#include <stdexcept>
using namespace std;

void foo(bool b) {
    if (b) {
        throw runtime_error("Error");
    } else {
        throw out_of_range("Error");
    }
    throw 42;
}
void bar(bool b) {
    if (b) {
        throw runtime_error("Error");
    } else {
        throw out_of_range("Error");
    }
    throw 42;
}

void handle_exception_with_lippincott_function() {
    try {
        throw;
    } catch (const out_of_range& e) {
        // handle out_of_range
        cout << "Handling out_of_range\n";
    } catch (const runtime_error& e) {
        // handle runtime_error
        cout << "Handling runtime_error\n";
    } catch (int i) {
        cout << "Handling int\n";
    }
}

int main()
{
   /* try {
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
    }*/

   try {
        foo(true);
    } catch (...) {
        handle_exception_with_lippincott_function();
    }
// ...
    try {
        bar(true);
    } catch (...) {
        handle_exception_with_lippincott_function();
    }
}