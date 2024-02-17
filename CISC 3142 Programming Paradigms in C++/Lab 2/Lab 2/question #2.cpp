//
//  question #2.cpp
//  Lab 2
//
//  Created by Bi Rong Liu on 2/17/24.
//
#include "string"
#include "iostream"
#include "fstream"
#include "iomanip"
using namespace std;

int main() {
    ifstream inFile;
    ofstream outFile;
    inFile.open("inData.txt");
    outFile.open("outData.txt");
    
    string a;
    inFile >> a;
    outFile << a;
    
    inFile.close();
    outFile.close();
}
