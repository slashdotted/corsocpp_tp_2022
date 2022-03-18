#include <iostream>
#include <string>

struct Owner {
    Owner(const std::string& n) : m_name{n}{
        std::cout << "Constructing Owner " << n << '\n';
    }
    /*~Owner() {
        std::cout << "Destroying Owner " << m_name << '\n';
    }*/
    std::string m_name; // we assume that std::string is able to copy itself
};

/*struct Owner {
    Owner(const std::string& n) : m_name{new std::string{n}}{
        std::cout << "Constructing Owner " << n << '\n';
    }
    ~Owner() {
        std::cout << "Destroying Owner " << m_name << '\n';
        delete m_name;
    }

    Owner(const Owner& o) : m_name{new std::string{*o.m_name}} {}

    Owner& operator=(const Owner& o) {
        *m_name = *o.m_name;
        return *this;
    }

    std::string *m_name; // we assume that std::string is able to copy itself
};*/

struct Engine {
    Engine() {
        std::cout << "Constructing Engine\n";
    }
    ~Engine() {
        std::cout << "Destroying Engine\n";
    }
    int m_year{2022};
};

struct Car {
    Car(const std::string& name,
        const std::string& owner_name) 
        : m_owner{new Owner{owner_name}}
    {
        std::cout << "Constructing Car " << name << '\n';
        ++m_instances;
    }

    // Copy constructor
    Car(const Car& c)
        : m_owner{new Owner{*c.m_owner}} { // we assume that Owner is able to copy itself
        std::cout << "Copy constructing Car " << '\n';
        ++m_instances;
    }

    // Copy assignment operator
    Car& operator=(const Car& c) {
        *m_owner = *c.m_owner; // we assume that Owner is able to copy itself
        return *this;
    }

    ~Car() {
        std::cout << "Destroying Car " << '\n';
        delete m_owner;
        --m_instances;
    }

    static int how_many_cars() {
        return m_instances;
    }

private:
    static int m_instances;
    Engine m_a;
    Owner *m_owner;
};

int Car::m_instances = 0; // static field initialization

// Construction of a copy
void foo(Car c) {
    std::cout << "I'm in foo\n";
    std::cout << "How many cars? " << Car::how_many_cars() << "\n";
}

// Construction of a copy
void foo2(const Car &c) {
    std::cout << "I'm in foo\n";
    std::cout << "How many cars? " << Car::how_many_cars() << "\n";
}

int main()
{
    Car b{"Supsi", "Amos"};
    foo(b);
    Car copy{b}; // Copy constructor
    std::cout << "How many cars? " << Car::how_many_cars() << "\n";

    Car d{"Usi", "Luca"};
    b = d; // Assignment of a copy, like b.operator=(d)
    std::cout << "How many cars? " << Car::how_many_cars() << "\n";
}
