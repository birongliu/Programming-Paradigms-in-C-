//
//  main.cpp
//  Lab 8
//
//  Created by Bi Rong Liu on 4/11/24.
//

#include <stdio.h>
#include <iostream>
#include "implement.cpp"
using namespace std;

int main() {
    productType prod1;
    productType prod2("Apple", "123", "Family Farm", 100, 5.99, 12);
    prod1.set("Pear", "1234", "Big Farm", 120, 3.99, 0);
    prod1.print();
    prod1.updateQuantitiesInStock(10);
    cout << prod1.getQuantitiesInStock() << endl;
    prod1.setPrice(15.5);
    cout << prod1.getPrice() << endl;
    prod1.print();
    return 0;
}
