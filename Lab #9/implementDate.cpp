//
//  implementDate.cpp
//  Lab #9
//
//  Created by Bi Rong Liu on 5/3/24.
//

#include <stdio.h>
#include "dateType.hpp"
#include "iostream"
using namespace std;

void dateType::setDate(int month, int day, int year) {
    dMonth = month;
    dDay = day;
    dYear = year;
};

int dateType::getDay() const {
    return dDay;
};

int dateType::getMonth() const {
    return dMonth;
};

int dateType::getYear() const {
    return dYear;
};

void dateType::printDate() const {
    cout << dMonth << "-" << dDay << "-" << dYear << endl;
};


dateType::dateType(int month, int day, int year) {
    dMonth = month;
    dDay = day;
    dYear = year;
};

