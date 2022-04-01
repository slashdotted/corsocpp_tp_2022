#include <iostream>
#include "employee.h"

Employee::Employee(const std::string &name, const std::string &institute, int nr)
    : m_name{name}, m_institute{institute},
      m_employeenr{nr}
{
    std::cout << "Constructing Employee" << std::endl;
}
Employee::~Employee()
{
    std::cout << "Destroying Employee" << std::endl;
}
const std::string & Employee::name() const
{
    return m_name;
}
const std::string & Employee::institute() const
{
    return m_institute;
}
int Employee::employeenr() const
{
    return m_employeenr;
}
const std::string & Employee::classname() const
{
    return "Employee";
}