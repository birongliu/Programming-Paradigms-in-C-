#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double length;
    double radius;
    int space;
    cout << "Enter length of the yard: ";
    cin >> length;

    cout << "Enter radius of a fully grown tree: ";
    cin >> radius;

    cout << "The required space between fully grown tree: ";
    cin >> space;
    double treeArea = M_PI * (pow(radius, 2));
    int numberOfTrees = floor(length / (treeArea + space));

    cout << "# of trees that can be plant in the yard: " << numberOfTrees << "\n";
    cout << "Total space that will be occupid by the fully grow tree: " << numberOfTrees * (treeArea + space);

    return 0;
}