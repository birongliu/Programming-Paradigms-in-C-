//
//  question #2.cpp
//  Lab 6
//
//  Created by Bi Rong Liu on 3/28/24.
//

#include <iostream>
using namespace std;
/**
 Write a method that sorts an array. You are going to sort the array by using the following algorithm:

    a) Find the smallest element within the array between index numbers 0 and n
  Once you find the smallest element, place it into index=0
     b) Find the next smallest element within the array between index numbers 1 and n
 Once you find the second smallest element, place it into index=1
     c) Find the next smallest element within the array between index numbers 2 and n
 Once you find the third smallest element, place it into index=2
     d) Repeat until you find the last element in the array and place it into index = n
 */

void swapElement(int &num1, int &num2);
void sortElement(int array[], int n);
int main() {
    int arr[] = { 1, 3, 2, 0 };
    sortElement(arr, sizeof(arr) / sizeof(arr[0]));
    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        cout << arr[i] << " ";
    }
}

void sortElement(int array[], int n){
    for(int i = 0; i < n; i++) {
        int minIndex = i;
        for(int j = i+1; j < n; j++) {
            if(array[j] < array[minIndex]) {
                minIndex = j;
            }
            if(minIndex != i) swapElement(array[minIndex], array[i]);
        }
    }
};


void swapElement(int &num1, int &num2) {
    int current = num1;
    num1 = num2;
    num2 = current;
}
