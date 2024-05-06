//
//  implementDoctor.cpp
//  Lab #9
//
//  Created by Bi Rong Liu on 5/3/24.
//

#include "doctorType.hpp"

doctorType::doctorType(string speciality) : personType("", "") {
    this->speciality = speciality;
};

void doctorType::setSpeciality(string speciality) {
    this->speciality = speciality;
}

string doctorType::getSpeciality() const {
    return speciality;
};
