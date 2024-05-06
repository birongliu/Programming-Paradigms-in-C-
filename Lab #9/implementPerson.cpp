//
//  implementPerson.cpp
//  Lab #9
//
//  Created by Bi Rong Liu on 5/3/24.
//

#include <stdio.h>
#include "personType.hpp"
#include "iostream"

void personType::print() const {
    cout << firstName + " " << lastName << endl;
}

void personType::setName(string first, string last) {
    firstName = first;
    lastName = last;
};

string personType::getFirstName() const {
    return firstName;
};

string personType::getLastName() const {
    return lastName;
};

personType::personType(string first, string last) {
    firstName = first;
    lastName = last;
};
