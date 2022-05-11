#include <iostream>
#include <unistd.h>
#include <vector>

struct Pod {
    Pod() {
        std::cout << "Constructing Pod\n";
    }

    ~Pod() {
        std::cout << "Destroying Pod\n";
    }

    Pod(const Pod&) {
        std::cout << "Copy constructing Pod\n";
        sleep(5);
    }

    Pod& operator=(const Pod&) {
        std::cout << "Copy assigning Pod\n";
        sleep(5);
        return *this;
    }

    Pod(Pod&&) {
        std::cout << "Move constructing Pod\n";
    }

    Pod& operator=(Pod&&) {
        std::cout << "Move assigning Pod\n";
        return *this;
    }
};

struct Handle {
    Handle() : m_Pod{new Pod} {}
    // Solution 1: prevent copy
    //Handle(const Handle&) = delete;
    //Handle& operator=(const Handle&) = delete;

    // Solution 2: implement copy
    Handle(const Handle& o) : m_Pod{new Pod{*o.m_Pod}}, m_Pod2{o.m_Pod2} {
        std::cout << "Copy constructing Handle\n";
    }
    Handle& operator=(const Handle& o) {
        std::cout << "Copy assigning Handle\n";
        *m_Pod = *o.m_Pod;
        m_Pod2 = o.m_Pod2;
        return *this;
    }

    ~Handle() {
        delete m_Pod;
    }

    // Move
    // std::move "converts" o.m_Pod2 into an R-Value
    Handle(Handle&& o) : m_Pod{o.m_Pod}, m_Pod2{std::move(o.m_Pod2)} {
        std::cout << "Move constructing Handle\n";
        o.m_Pod = nullptr;
    }

    Handle& operator=(Handle&& o) {
        std::cout << "Move assigning Handle\n";
        // Delete the old Pod object (otherwise we have a leak)
        delete m_Pod;
        // "Steal" the allocated memory
        m_Pod = o.m_Pod;
        // Reset the pointer inside the temporary object (otherwise we will have a double free)
        o.m_Pod = nullptr;

        // std::move "converts" o.m_Pod2 into an R-Value
        m_Pod2 = std::move(o.m_Pod2);
        
        return *this;
    }

    Pod* m_Pod;
    Pod m_Pod2;
};

void foo(Handle v) {

}

Handle bar() {
    Handle h;
    return h;
}

// Takes an L-value reference to Handle
void byref(Handle& o) {
    std::cout << "L-Value Ref\n";
}

// Takes an R-value reference to Handle
void byref(Handle&& o) {
    std::cout << "R-Value Ref\n";
}

int main() {
    Handle h1;
    Handle h2;
    h2 = bar();
    h1 = h2;
    h1 = h2;
    foo(h1);
    byref(h1);
    byref(bar());
}