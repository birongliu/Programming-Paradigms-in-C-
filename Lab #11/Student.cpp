//
//  Student.cpp
//  Lab #11
//
//  Created by Bi Rong Liu on 5/14/24.
//

#include "Student.hpp"

int Student::getId() {
    return this->id;
}

string Student::getName() {
    return this->name;
}

double Student::getGrade() {
    return this->grade;
}
Student::Student(int id, string name, double grade) {
    this->id = id;
    this->name = name;
    this->grade = grade;
};

Student::Student() {
    this->id = 0;
    this->name = "Unknown Student";
    this->grade = 0;
}
