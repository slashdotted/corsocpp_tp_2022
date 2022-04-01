#ifndef LECTURER
#define LECTURER
#include "employee.h"
#include <string>

// TODO: Make Lecturer an employee
class Lecturer {
public:
    Lecturer(const std::string &name, const std::string &institute, int nr,
             const std::string &studies, const std::string &course);
    ~Lecturer();
    const std::string &studies() const;
    const std::string &course() const;
    std::string classname() const;

protected:
    std::string m_studies;
    std::string m_course;
};
#endif // LECTURER