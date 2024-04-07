//
//  question #6.cpp
//  Lab 6
//
//  Created by Bi Rong Liu on 3/28/24.
//

#include "iostream"
using namespace std;
namespace myMath {
 int add(int numOne[3][3], int numTwo[3][3], int size) {
     int result = 0;
     for(int i = 0; i < size; i++) {
         for(int j = 0; j < size; j++) {
             result += numOne[i][j] + numTwo[i][j];
         }
     }
     return result;
 };
int sub(int numOne[3][3], int numTwo[3][3], int size) {
    int result = 0;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            result += numOne[i][j] - numTwo[i][j];
        }
    }
    return result;
   };
}

int main() {
    int table[3][3] = {
        {2, 2, 2},
        {2, 2, 2},
        {2, 2, 2}
    };
    int tableTwo[3][3] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    cout << myMath::add(table, tableTwo, sizeof(table) / sizeof(table[0])) << "\n";
    cout << myMath::sub(table, tableTwo, sizeof(table) / sizeof(table[0]));
}
