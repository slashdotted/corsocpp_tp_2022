
#include "lecturer.h"
#include <iostream>

Lecturer::Lecturer(const std::string &name, const std::string &institute,
                   int nr, const std::string &studies,
                   const std::string &course)
    : Employee{name, institute, nr}, m_studies{studies}, m_course{course} {
    std::cout << "Costructing Lecturer" << std::endl;
}

Lecturer::~Lecturer() {
    std::cout << "Destroying Lecturer" << std::endl;
}

const std::string &Lecturer::studies() const {
    return m_studies;
}

const std::string &Lecturer::course() const {
    return m_course;
}

std::string Lecturer::classname() const {
    return "Lecturer";
}