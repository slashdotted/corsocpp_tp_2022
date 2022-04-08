#include <iostream>
#include <string>
#include "employee.h"
#include "researcher.h"
#include "lecturer.h"
#include "lecturerresearcher.h"

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

int main() {
    using std::cout;
    LecturerResearcher john{"John", "DTI", 456, "Blabla", "FooFoo", "Coffee", 0.6};

    // static_cast<DestType>(source)
    // =============================
{
    // You can static_cast values
    Employee e = static_cast<Employee>(john);

    // You can static_cast refs or pointers
    auto re = static_cast<Researcher&>(john);
    auto le = static_cast<Lecturer*>(&john);

    auto ee = static_cast<Employee*>(&john);
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
    if (alicelr) {
        std::cout << alicelr << '\n';
    }

    try {
        LecturerResearcher& alicelr2 = dynamic_cast<LecturerResearcher&>(alice);
    } catch(...) {

    }
    
    //void* aliceptr = &alice;
    //LecturerResearcher* aliceptr2 = dynamic_cast<LecturerResearcher*>(aliceptr);
    const LecturerResearcher* calicelr = dynamic_cast<LecturerResearcher*>(&alice);
    LecturerResearcher* ncalicelr = const_cast<LecturerResearcher*>(calicelr);
}

}

