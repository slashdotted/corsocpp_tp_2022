#include <iostream>
#include <string>
#include "employee.h"
#include "researcher.h"
#include "lecturer.h"
#include "lecturerresearcher.h"
#include <map>

struct Generator {

    int get_value(int k) const {
        auto nc_this = const_cast<Generator*>(this);
        if (m_cache.count(k)) {
            return m_cache.at(k);
        } else {
            auto r = 42*k;
            nc_this->m_cache[k] = r;
            return r;
        }
    }

private:
    std::map<int, int> m_cache;
};

void fn(const Generator& o) {
    o.get_value(5);
}

void employee_addr(Employee* ptr) {
    std::cout <<"Address of employee: " << (intptr_t) ptr << '\n';
}

void researcher_addr(Researcher* ptr) {
    std::cout <<"Address of researcher: " << (intptr_t) ptr << '\n';
}

void lecturer_addr(Lecturer* ptr) {
    std::cout <<"Address of lecturer: " << (intptr_t) ptr << '\n';
}

void lecturerresearcher_addr(LecturerResearcher* ptr) {
    std::cout <<"Address of lecturer researcher: " << (intptr_t) ptr << '\n';
}

// Emulating instanceof
bool instance_of_lecturer(Employee* e) {
    return dynamic_cast<Lecturer*>(e);
}

int main() {
    using std::cout;
    LecturerResearcher john{"John", "DTI", 456, "Blabla", "FooFoo", "Coffee", 0.6};

    // static_cast<DestType>(source)
    // =============================
{
    // You can static_cast values
    Employee e = static_cast<Employee>(john);

    // static_cast of enum class
    enum class Importance { LOW, MEDIUM, HIGH};
    int a = static_cast<int>(Importance::MEDIUM);
    auto b = static_cast<Importance>(2);

    // You can static_cast refs or pointers
    auto re = static_cast<Researcher&>(john);
    auto le = static_cast<Lecturer*>(&john);

    auto ee = static_cast<Employee*>(&john);
    
    // Cannot static_cast (downcast) if we are traversing a virtual derivation
    // Lecturer* lee = static_cast<Lecturer*>(ee);

    Lecturer alice{"Alice", "DTI", 535, "Foo", "Bar"};
    LecturerResearcher* alicelr = static_cast<LecturerResearcher*>(&alice);
    std::cout << alicelr->researchpercentage() << '\n';
}
    // dynamic_cast<DestType>(source)
    // =============================
{   
    // You cannot dynamic_cast values 
    // Employee e = dynamic_cast<Employee>(john);

    // Upcasting works as expected

    // You can dynamic_cast refs or pointers
    auto re = dynamic_cast<Researcher&>(john);
    auto le = dynamic_cast<Lecturer*>(&john);
    auto ee = dynamic_cast<Employee*>(&john);


    Lecturer alice{"Alice", "DTI", 535, "Foo", "Bar"};
    LecturerResearcher* alicelr = dynamic_cast<LecturerResearcher*>(&alice);
    if (alicelr) { // nullptr
        std::cout << alicelr << '\n';
    }

    try {
        LecturerResearcher& alicelr2 = dynamic_cast<LecturerResearcher&>(alice);
    } catch(...) {
        // the cat has failed
    }
    
    //void* aliceptr = &alice;
    //LecturerResearcher* aliceptr2 = dynamic_cast<LecturerResearcher*>(aliceptr);
    const LecturerResearcher* calicelr = dynamic_cast<LecturerResearcher*>(&alice);
    LecturerResearcher* ncalicelr = const_cast<LecturerResearcher*>(calicelr);
}

}

