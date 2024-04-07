//
//  question #3.cpp
//  Lab 6
//
//  Created by Bi Rong Liu on 3/28/24.
//

#include <iostream>
using namespace std;

void generateMultiplicationTable(int table[9][9], int n);

int main() {
    int table[9][9];
    int n = sizeof(table) / sizeof(table[0]);
    generateMultiplicationTable(table, n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

void generateMultiplicationTable(int table[9][9], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            table[i][j] = (i + 1) * (j + 1);
        }
    }
}
