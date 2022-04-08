#ifndef LECTURERRESEARCHER
#define LECTURERRESEARCHER

#include "lecturer.h"
#include "researcher.h"

// To derive from two classes just list them 
class LecturerResearcher : public Lecturer, public Researcher
{
public:
    LecturerResearcher(const std::string& name, 
                    const std::string&  institute,
                    int nr,
                    const std::string&  studies, 
                    const std::string&  course, 
                    const std::string&  researcharea, 
                    double researchpercentage);

    double researchpercentage() const;
    //std::string name() const;

    std::string classname() const override; 

protected:
    double m_researchpercentage;
};

#endif