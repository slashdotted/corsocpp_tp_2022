#ifndef EMPLOYEE
#define EMPLOYEE

#include <string>

class AbstractEmployee {
    // virtual makes Employee a polymorphic type
    // virtual makes classname a polymorphic method
    virtual std::string classname() const = 0;
    // if we add = 0, we call the method "pure virtual"
    // there is no implementation here for pure virtual methods
};


class Employee : public AbstractEmployee {
public:
    Employee(const std::string &name, const std::string &institute, int nr);
    ~Employee();
    const std::string &name() const;
    const std::string &institute() const;
    int employeenr() const;

    std::string classname() const override; 

protected:
    std::string m_name;
    std::string m_institute;
    int m_employeenr;
};
#endif // EMPLOYEE