//
//  question #4.cpp
//  Lab 6
//
//  Created by Bi Rong Liu on 3/28/24.
//

#include "iostream"
using namespace std;
string isPalindrome(string word);
int main() {
    cout << isPalindrome("aba") << endl;
}

string isPalindrome(string word) {
    for(int i = 0; i < word.size(); i++) {
        if(word[i] != word[word.size() - i - 1]) return "false";
    }
    return "true";
}

