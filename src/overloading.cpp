#include <iostream>
using std::cout, std::endl;

class Example {
public:
    void f(double x)
    {
        cout << "f(double x)" << endl;
    }
    void f(int x)
    {
        cout << "f(int x)" << endl;
    }
};

int main()
{
    Example e;
    e.f(3.2);
    e.f(3);
}