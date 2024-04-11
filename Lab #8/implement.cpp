//
//  question #1.cpp
//  Lab 8
//
//  Created by Bi Rong Liu on 4/10/24.
//

#include <stdio.h>
#include <iostream>
#include "string"
using namespace std;
#include "productType.h"

/*
Give the line number containing the constructor that is executed in each of the following declarations. (In other words, which constructors will be invoked if the following objects are created. You will not write any code here just write line numbers to corresponding objects)
 i. productType product1;
 ii. productType product2("Microwave", "M3562", "GeneralPool", 35, 175.00, 0.1);
 iii. productType product3("D1290", 25, 375.00, 0.05);
 iv. productType product4(10, 8.50, 0.2);
 ----------------------------------------------
 i.productType(); (Line 4) will invoke given that the object is created using productType product1;
 ii.productType(string, string, string, int, double, double); (Line 7) will be invoke because first three parameter passed in are string and fourth one is int and rest two are double;
iii. productType(string, int, double, double); (Line 6) will be invoked because first parameter is string, followed by int, double, and lastly double;
 iv.productType(int, double, double); (Line 5) will be invoked it.
*/

//b. Write the definition of the constructor in Line 4 so that the instance variables are initialized to "", "", "", 0, 0.0, and 0.0, respectively.
productType::productType() {
    productName = ""; //Line 18
    id = ""; //Line 19
    manufacturer = ""; //Line 20
    quantitiesInStock = 0; //Line 21
    price = 0.0; //Line 22
    discount = 0.0; //Line 23
}

//c. Write the definition of the constructor in Line 5 so that the string instance variables are initialized to "", and the other instance variables are initialized according to the parameters. Instance variables quantitiesInStock, price, and discount must be nonnegative.


productType::productType(int quantitiesInStock, double price, double discount) {
    this->productName = "";
    this->id = "";
    this->manufacturer = "";
    this->quantitiesInStock = quantitiesInStock >= 0 ? quantitiesInStock : 0;
    this->price = price >= 0 ? price : 0;
    this->discount = discount >= 0 ? discount : 0;
}

//d. Write the definition of the constructor in Line 6 so that the instance variables productName and manufacturer are initialized to the empty string, instance variable id is initialized according to the first parameter, and the remaining instance variables are initialized according to the last three parameters. Instance variables quantitiesInStock, price, and discount must be nonnegative.
productType::productType(string id, int quantitiesInStock, double price, double discount) {
    this->productName = "";
    this->manufacturer = "";
    this->id = id;
    this->quantitiesInStock = quantitiesInStock >= 0 ? quantitiesInStock : 0;
    this->price = price >= 0.0 ? price : 0.0;
    this->discount = discount >= 0.0 ? discount : 0.0;
}

//e. Write the definition of the constructor in Line 7 so that the instance variables are initialized according to the parameters. Instance variables quantitiesInStock, price, and discount must be nonnegative.

productType::productType(string productName, string id, string manufacturer, int quantitiesInStock, double price, double discount) {
    this->productName = productName;
    this->id = id;
    this->manufacturer = manufacturer;
    this->quantitiesInStock = quantitiesInStock >= 0 ? quantitiesInStock : 0;
    this->price = price >= 0.0 ? price : 0.0;
    this->discount = discount >= 0 ? discount : 0.0;
};
//2. Consider the definition of the class productType as given in Exercise 1.
//a. Write the definition of the function set so that instance variables are set according to the paramaters. Instance variables quantitiesInStock, price, and discount must be nonnegative.

void productType::set(string productName, string id, string manufacturer, int quantitiesInStock, double price , double discount) {
    this->productName = productName;
    this->manufacturer = manufacturer;
    this->quantitiesInStock = quantitiesInStock >= 0 ? quantitiesInStock : 0;
    this->price = price >= 0.0 ? price : 0.0;
    this->discount = discount >= 0 ? discount : 0.0;
    this->id = id;
}
//b. Write the definition of the function print to output the values of the instance variables.
void productType::print() const {
    cout << "{" << endl;
    cout << "\tid " << id << endl;
    cout << "\tproductName: " << productName << endl;
    cout << "\tmanufacturer: " << manufacturer << endl;
    cout << "\tquantitiesInStock: " << quantitiesInStock << endl;
    cout << "\tprice: " << price << endl;
    cout << "\tdiscount " << discount << endl;
    cout << "}" << endl;
}
//c. Write the definition of the function setQuantitiesInStock to set the value of the instance variable quantitiesInStock according to the parameter.
void productType::setQuantitiesInStock(int amount) {
    this->quantitiesInStock = amount;
}

//d. Write the definition of the function updateQuantitiesInStock to update the value of instance variable quantitiesInStock by adding the value of the parameter.

void productType::updateQuantitiesInStock(int amount) {
    this->quantitiesInStock += amount;
}

//e. Write the definition of the function getQuantitiesInStock to return the value of instance variable quantitiesInStock.
int productType::getQuantitiesInStock() const {
    return quantitiesInStock;
}

//f. Write the definition of the function setPrice to set the value of the instance variable price according to the parameter.
void productType::setPrice(double price) {
    this->price = price;
}

//g. Write the definition of the function getPrice to return the value of the instance variable price.
double productType::getPrice() const {
    return price;
}

//h. Write the definition of the function setDiscount to set the value of the instance variable discount according to the parameter.
void productType::setDiscount(double d){
    discount = d;
}

//i. Write the definition of the function getDiscount to return the value of the instance variable discount
double productType::getDiscount() const {
    return discount;
}


/*
3) Consider the definition of the class productType as given in Exercise 1. Which function members are accessors, and which are mutators?
Accessors:
  void print() const; 
  int getQuantitiesInStock() const;
  double getPrice() const; 
  double getDiscount() const;

Mutators:
  void set(string, string, string, int, double, double); 
  void setQuantitiesInStock(int x);  
  void updateQuantitiesInStock(int x); 
  void setPrice(double x); 
  void setDiscount(double d); 
*/