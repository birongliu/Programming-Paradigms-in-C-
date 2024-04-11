//
//  question #5.cpp
//  Lab 6
//
//  Created by Bi Rong Liu on 3/28/24.
//


#include "iostream"
using namespace std;
string reverseString(string word);

int main() {
    cout << reverseString("hello") << "\n";
}

string reverseString(string word) {
    string result = "";
    for(long i = word.size(); i >= 0; i--) {
        result += word[i];
    }
    return result;
}

