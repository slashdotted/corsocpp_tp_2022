#include "pimpl.h"

struct MyDataType::pimpl {
    std::string s;
    int m;
};

MyDataType::MyDataType() : m_private{std::make_unique<pimpl>()} {}

MyDataType::~MyDataType() = default;

int MyDataType::getM() const {
    return m_private->m;
}

std::string MyDataType::getS() const {
    return m_private->s;
}


