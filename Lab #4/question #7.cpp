//
//  question #7.cpp
//  Lab 4
//
//  Created by Bi Rong Liu on 3/7/24.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;
void reverseDigit(int &digits) {
    bool flags = false;
    int result = 0;
    if(digits < 0) {
        flags = true;
        digits = -(digits);
    }
    
    while(digits > 0) {
        int digit = digits % 10;
        result = result*10+digit;
        digits /= 10;
    }
    if(flags) {
        digits = -(digits);
        flags = true;
    }
    digits = result;
}
int main() {
    int digits;
    cout << "Enter digits ";
    cin >> digits;
    
    reverseDigit(digits);
    cout << "digit reversed " << digits;
}
