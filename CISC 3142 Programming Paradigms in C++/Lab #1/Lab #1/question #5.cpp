using namespace std;
#include <iostream>

int main() {
    double capacity;
    cout << "Enter the capacity in gallons of an automobile " << endl;
    cin >> capacity;
    double miles;
    cout << "Enter the miles per gallon the automobile can be driven" << endl;
    cin >> miles;
    cout << "There are " << capacity * miles << " miles that can be driven without refueling." << endl;
    
    return 0;
}