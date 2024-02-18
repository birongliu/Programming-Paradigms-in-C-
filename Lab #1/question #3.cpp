#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    double radius;
    double area;
    double circumference;
    const double PI = 3.14;
    cout << "Enter the radius: " << endl;
    cin >> radius;
    circumference = 2 * PI * radius;
    cout << "Circumference = " << circumference << endl;
    area = PI * radius;
    cout << "Area = " << area << endl;
    return 0;
}