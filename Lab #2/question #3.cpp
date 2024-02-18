#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   double weight;
   cout << "Enter the weight in kilograms: ";
   cin >> weight;
   cout << fixed << showpoint << setprecision(2);
   double pounds = weight * 2.2;
   cout << "Weight in kilograms: " << weight << "\n";
   cout << "Weight in pounds: " << pounds;
   return 0;
}