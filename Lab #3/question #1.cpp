//
//  main.cpp
//  Lab 3
//
//  Created by Bi Rong Liu on 2/21/24.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int nums;
    cout << "Enter the number between 0 through 35: " << endl;
    cin >> nums;
    
    
    if(nums <= 9) {
        cout << nums;
    }
    
    if(nums <=35) {
        char charNum = static_cast<char>(55+nums);
        cout << charNum << endl;
    }
    
    return 0;
}
