#include "lecturerresearcher.h"

LecturerResearcher::LecturerResearcher(const std::string& name, 
                    const std::string&  institute,
                    int nr,
                    const std::string&  studies, 
                    const std::string&  course, 
                    const std::string&  researcharea, 
                    double researchpercentage) {
                        

}

double LecturerResearcher::researchpercentage() const {
    return m_researchpercentage;
}