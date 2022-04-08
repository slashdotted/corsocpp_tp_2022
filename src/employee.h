#ifndef EMPLOYEE
#define EMPLOYEE

#include <string>

class Employee {
public:
    Employee(const std::string &name, const std::string &institute, int nr);
    ~Employee();
    const std::string &name() const;
    const std::string &institute() const;
    int employeenr() const;

    // virtual makes Employee a polymorphic type
    // virtual makes classname a polymorphic method
    virtual std::string classname() const; 

protected:
    std::string m_name;
    std::string m_institute;
    int m_employeenr;
};
#endif // EMPLOYEE