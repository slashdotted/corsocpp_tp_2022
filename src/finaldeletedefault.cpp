class Base final {};

/* Error! Cannot derive Base
class Derived : public Base
{
};
*/

class Base2 {
public:
    virtual void f() {}
};

class Derived2: public Base2 {
public:
    void f() override final {
    }
};

class DoubleDerived2 : public Derived2 {
public:
    // Error! Cannot override f()
    //void f() override {}
};

class Example {
public:
    Example() = default;
    ~Example() { /*...*/ }

    Example(const Example &) = delete;
    Example &operator=(const Example &) = delete;
};

void foo(Example v) {}

struct Copyable {
    Copyable() = default;
    Copyable(const Copyable&) {
        /* ... */
    }
    Copyable& operator=(const Copyable&) {
        return *this;
    }
    ~Copyable() = default;
};

int main() {
    Example e;
    Example f;
    Copyable c;
    // e = f;  // Error: copy assignment operator has been deleted
    // foo(e); // Error: copy constructor has been deleted
}