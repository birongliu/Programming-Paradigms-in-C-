//
//  question #4.cpp
//  Lab 4
//
//  Created by Bi Rong Liu on 3/7/24.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int Apopulations, Bpopulations;
    double Agrowth, Bgrowth;
    
    cout << "Enter a the population for A: ";
    cin >> Apopulations;
    cout << "Enter a the population for B: ";
    cin >> Bpopulations;
    
    cout << "Enter a the growth for A: ";
    cin >> Agrowth;
    cout << "Enter a the growth for B: ";
    cin >> Bgrowth;
    
    Agrowth /= 100;
    Bgrowth /= 100;
    
    int years = 0;
    while (Apopulations >= Bpopulations) {
        Apopulations += Apopulations*Agrowth;
        Apopulations+=Apopulations*Bgrowth;
        years++;
    }
    
    cout << "After " << years << "Will be greater than or equal to the population of town B and the population of both towns at same time";
}

