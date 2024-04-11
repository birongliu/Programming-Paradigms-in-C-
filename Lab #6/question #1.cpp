//
//  main.cpp
//  Lab 6
//
//  Created by Bi Rong Liu on 3/28/24.
//

#include <iostream>
using namespace std;

int seqSearch(const int list[], int listLength, int searchItem) {
    for(int i = 0; i < listLength; i++) {
        if(list[i] == searchItem) return i;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int list[] = { 20, 10, 100 };
    int result = seqSearch(list, sizeof(list) / sizeof(list[0]), 100);
    cout << result << endl;
}

