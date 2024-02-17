#include <iostream>
#include<cmath>
using namespace std;

int main() {
    double number;
    cout << "Enter a input that are decimal number ie (1.0)" << endl;
    cin >> number;
    
    cout << "The output of nearest integer is " << static_cast<int>(round(number)) << endl;
    return 0;
}
