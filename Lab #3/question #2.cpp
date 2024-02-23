//
//  question #2.cpp
//  Lab 3
//
//  Created by Bi Rong Liu on 2/21/24.
//

#include <iostream>
using namespace std;

int main() {
    const double TEN_PERCENT = 0.10;
    const double TWENTY_PERCENT = 0.20;
    const double THIRTY_PERCENT = 0.30;
    const double ADDITIONAL_PERCENT = 0.5;
    const double COST_RENTING_PER_ROOM = 100;

    double salesTaxes;
    int numberOfDayTheRoomAreBooked,numberOfRoom;
    cout << "Enter the number of room booked" << endl;
    cin >> numberOfRoom;
    cout << "Enter the number of days the rooms are booked" << endl;
    cin >> numberOfDayTheRoomAreBooked;
    cout << "Enter the sales taxes (as percents)" << endl;
    cin >> salesTaxes;
    
    double discount = 0;
    if(numberOfDayTheRoomAreBooked > 3) {
        discount += ADDITIONAL_PERCENT;
    }
    if(numberOfRoom >= 30) {
        discount += THIRTY_PERCENT;
    }
    if(numberOfRoom >= 20) {
        discount += TWENTY_PERCENT;
    }
    
    if(numberOfRoom >= 10) {
        discount += TEN_PERCENT;
    }
    
    double totalCost = COST_RENTING_PER_ROOM * numberOfRoom * numberOfDayTheRoomAreBooked;
    
    double totalCostAfterDiscount = totalCost * (1 - discount);
    double totalSalesTax = totalCostAfterDiscount * (salesTaxes / 100);
    double totalAmount = totalCostAfterDiscount + totalSalesTax;
    
    
    cout << "Total Cost renting a room (without discount): " << totalCost << endl;
    cout << "discount of each rooms as percent: " << totalCostAfterDiscount << endl;
    cout << "Sales taxes: " << totalSalesTax << endl;
    cout << "total billing: " << totalAmount << endl;
    return 0;
}
