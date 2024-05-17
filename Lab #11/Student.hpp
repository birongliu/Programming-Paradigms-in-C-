//
//  Student.hpp
//  Lab #11
//
//  Created by Bi Rong Liu on 5/14/24.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <string>
#include "vector"
using namespace std;

class Student {
    int id;
    string name;
    double grade;
    
public:
    int getId();
    string getName();
    double getGrade();
    Student();
    Student(int id, string name, double grade);
    void setId();
    void setName();
    void setGrade();

};
#endif /* Student_hpp */
