//
//  main.cpp
//  Lab 2
//
//  Created by Bi Rong Liu on 2/17/24.
//
/**
 Suppose x, y, and z are int variables and ch is a char variable. Consider the following input: 78 86 18 #42 &

 What value (if any) is assigned to x, y, z, and ch after each of the following statements executes? (Use the same input without changing the order for each statement and run each statement separately)



 cin >> x >> y >> z >> ch;
 ---------------------
    x = 78
    y = 86
    z = 18
    ch = '#'


 cin >> ch >> x >> y >> z;
 ---------------------
    ch = 7
    x = 8
    y = 86
    z = 18

 cin >> x;
 cin.get(ch);
 cin >> y >> z;
 ---------------
    x = 78
    cin.get() = " "
    y = 86
    z = 18


 cin >> x >> ch >> y >> z;
      cin.get(ch);
 -------------------
    x = 78
    ch = 8
    y = 6
    z = 18
    cin.get(ch) = " "

 cin >> x >> y >> z;
 -----------------
    x = 78
    y = 86
    z = 18
 
 
 
 
 
 
 
 
 
 
 
 */
