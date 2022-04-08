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

    // cout << "Name: " << john.Researcher::name();
    cout << "Name: " << john.name();
    cout  << " Research area: " <<john.researcharea()
        << " %:"<< john.researchpercentage() << " Course:"<< john.course() << '\n';

    lecturerresearcher_addr(&john);
    lecturer_addr(&john); 
    researcher_addr(&john); 
    employee_addr(&john); 
}
