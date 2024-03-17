//
//  question #1.cpp
//  Lab 4
//
//  Created by Bi Rong Liu on 3/6/24.
//

#include <iostream>
using namespace std;
int main() {
    int input;
    int sum = 0;
    while (true) {
        cout << "Enter a whole number: ";
        cin >> input;
        if(cin.fail()) {
            cout << "Invalid input. Exiting the loop.\n";
            break;
        }
        sum += input;
       }
    cout << sum << endl;
    return 0;
}
