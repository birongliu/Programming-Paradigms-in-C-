//
//  question #3.cpp
//  Lab 3
//
//  Created by Bi Rong Liu on 2/22/24.
//

#include <iostream>
using namespace std;

double calucateMenBodyFat(double weight, double waist) {
    double A1 = (weight * 1.082) + 94.42;
    double A2 = waist * 4.15;
    double B = A1 - A2;
    double fat = weight - B;
    return (fat * 100) / weight;
}

double calucateWomanBodyFat(double weight, double waist, double wrist, double hip, double forearm) {
    double A1 = (weight * 0.732) + 8.987;
    double A2 = wrist / 3.140;
    double A3 = waist * 0.157;
    double A4 = hip / 0.249;
    double A5 = forearm / 0.434;
    double B = A1 + A2 + A3 + A4 + A5;
    double fat = weight - B;
    return (fat * 100) / weight;
}

int main() {
   int gender;
   double weight, waist, wrist, hip, forearm;
   cout << "please enter 1=men | 2=woman" << endl;
   cin >> gender;
   cout << "please provide weight " << endl;
   cin >> weight;

   cout << "please provide waist " << endl;
   cin >> waist;

   switch (gender) {
   case 1: {
      double calucated = calucateMenBodyFat(weight, waist);
      cout << "The body fat are " << calucated << endl;
      break;
   }
   default:
      cout << "please provide wrist " << endl;
      cin >> wrist;   
      cout << "please provide hip " << endl;
      cin >> hip;
      cout << "please provide forearm " << endl;
      cin >> forearm;
      double calucated = calucateWomanBodyFat(weight, waist, wrist, hip, forearm);
      cout << "The body fat are " << calucated << endl;
      break;
   }
   return 0;
}

