//
//  doctorType.hpp
//  Lab #9
//
//  Created by Bi Rong Liu on 5/3/24.
//

#ifndef doctorType_hpp
#define doctorType_hpp

#include "personType.hpp"
#include "string"

class doctorType : public personType {
private:
    string speciality;
public:
    doctorType(string speciality = "");
    void setSpeciality(string speciality);
    string getSpeciality() const;
};

#endif

