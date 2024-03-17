//
//  question #2.cpp
//  Lab 4
//
//  Created by Bi Rong Liu on 3/6/24.
//

#include <iostream>
using namespace std;

int fibonacci(int n) {
    if(n < 0) return 0;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int num;
    cout << "Enter a n number for this fib: " << endl;
    cin >> num;
    int i = fibonacci(num);
    cout << i << endl;
    return 0;
}

