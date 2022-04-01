#include <iostream>
#include <string>
#include "employee.h"
#include "researcher.h"
#include "lecturer.h"

void printName(const Employee& e) {
    std::cout << "The employee is called: " << e.name() << "\n";
}

void printName(const Employee* e) {
    std::cout << "The employee is called: " << e->name() << "\n";
}

void printNameByValue(Employee e) {
    std::cout << "The employee is called: " << e.name() << "\n";
}


void printClass(const Employee& e) {
    std::cout << "The employee is: " << e.classname() << "\n";
}

void printClass(const Employee* e) {
    std::cout << "The employee is: " << e->classname() << "\n";
}

void printClassByValue(Employee e) {
    std::cout << "The employee is: " << e.classname() << "\n";
}


int main() {
    Employee elvis{"Elvis", "SI", 123};
    Researcher bob{"Bob", "DTI", 124, "Networking"};
    Lecturer alice{"Alice", "DTI", 125, "Security", "Lab"};
    printName(elvis);
    printName(bob);
    printName(alice);
    printName(&elvis);
    printName(&bob);
    printName(&alice);
    printNameByValue(elvis);
    printNameByValue(bob);
    printNameByValue(alice);

    std::cout << elvis.classname() << '\n';
    std::cout << bob.classname() << '\n';
    std::cout << alice.classname() << '\n';

    printClass(elvis);
    printClass(bob);
    printClass(alice);

}
