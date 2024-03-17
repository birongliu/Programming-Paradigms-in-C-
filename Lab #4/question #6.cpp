//
//  question #5.cpp
//  Lab 4
//
//  Created by Bi Rong Liu on 3/7/24.
//

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
bool isPalindrome(string str) {
    for(int i = 0; i < str.length() / 2; i++) {
        if(str[i] == str[str.length() - i - 1]) return true;
    }
    return false;
}
int main() {
    string str;
    cout << "Enter a string";
    cin >> str;
    if(isPalindrome(str)) {
        cout << "it is a palindrome";
    } else {
        cout << "it not a palindrome";
    }
    return 0;
}
