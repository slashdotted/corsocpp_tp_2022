#include "researcher.h"
#include <iostream>

Researcher::Researcher(const std::string &name, const std::string &institute,
                       int nr, const std::string &researcharea)
    : Employee{name, institute, nr}, m_researcharea{researcharea} {
    std::cout << "Costructing Researcher" << std::endl;
}

Researcher::~Researcher() {
    std::cout << "Destroying Researcher" << std::endl;
}

const std::string &Researcher::researcharea() const {
    return m_researcharea;
}

std::string Researcher::classname() const {
    return "Researcher";
}