//
//  main.cpp
//  Lab #11
//
//  Created by Bi Rong Liu on 5/14/24.
//
/*Student Database
 
 You are tasked with creating a program to manage a database of student records using C++ vectors and iterators.

 x Define a class named Student with the following private attributes:

 x name (string): to store the name of the student.
 x id (int): to store the unique ID of the student.
 x grade (double): to store the grade of the student. 
   x  •    Implement a constructor for the Student class that initializes the attributes.

   x •    Create a vector named studentDatabase to store Student objects.

   x  •    Write a function addStudent that takes input from the user for the name, ID, and grade of a student, creates a Student object with the input data, and adds it to the studentDatabase.

     •    Write a function displayStudents that iterates through the studentDatabase using iterators and displays the details of each student (name, ID, and grade) on the console.

     •    Write a function findStudent that takes an ID as input and searches for a student with that ID in the studentDatabase. If found, display the details of the student; otherwise, display a message indicating that the student was not found.

     •    Write a main function to test your implementation. In the main function, provide a menu-driven interface to allow the user to perform the following operations:

     •    Add a new student to the database.
     •    Display all students in the database.
     •    Find a student by ID.
     •    Exit the program.
     •    Ensure error handling for invalid inputs and proper memory management.
**/
#include <iostream>
#include <vector>
#include "Student.hpp"
#include "string"

int globalId = 0;
void findStudent(vector<Student> &studentDB, int id);
void generateBanner();
char generateOptions();
void displayStudentTemplete(Student* student);
char createStudent(vector<Student> &studentDB, bool shouldShow);
void addStudent(vector<Student> &studentDB, int id, string name, double grade);
void displayStudents(vector<Student> &studentDB);
char backPromptOptions(string prompt);

int main(int argc, const char * argv[]) {
    vector<Student> studentDatabase;
    char userInput;
    generateBanner();
    userInput = generateOptions();
    while (true) {
        switch (userInput) {
            case 'a': {
                char options = createStudent(studentDatabase, true);
                if(options == 'e') {
                    userInput = generateOptions();
                } else if(options == 'a') {
                    options = createStudent(studentDatabase, false);
                } else {
                    char prompt = backPromptOptions("a=Add more students to database");
                    if(prompt == 'e') userInput = generateOptions();
                }
                break;
            }
            case 'b': {
                displayStudents(studentDatabase);
                char options = backPromptOptions("");
                if(options == 'e') userInput = generateOptions();
                break;
            }
            case 'c': {
                int search;
                cout << "Please provide a id to search: ";
                cin >> search;
                findStudent(studentDatabase, search);
                char option = backPromptOptions("c=Another search");
                if(option == 'e') {
                    userInput = generateOptions();
                } else {
                    char prompt = backPromptOptions("c=Another search");
                    if(prompt == 'e') userInput = generateOptions();
                }
                break;
            }
            case 'd': {
                cout << "Exiting the program" << endl;
                return 0;
            }
            default: {
                cout << "Invalid options provided" << endl;
                cin >> userInput;
                break;
            }
        }
    }
}

char backPromptOptions(string prompt) {
    char userInput;
    if(prompt != "") cout << prompt << endl;
    cout << "e=Exit menu" << endl;
    cout << "Please provide options: ";
    cin >> userInput;
    return userInput;
}

char createStudent(vector<Student> &studentDB, bool shouldShow) {
    if(shouldShow) cout << "\nRegister Student\n";
    string name;
    double grade;
    cout << "Enter the name of the student: ";
    cin >> name;
    
    cout << "Enter the grade of the student: ";
    cin >> grade;
    
    addStudent(studentDB, globalId++, name, grade);
    cout << "Successfully added to database" << endl;
    return backPromptOptions("a=Add more students to database");
};

void addStudent(vector<Student> &studentDB, int id, string name, double grade) {
    Student newStudent(id, name, grade);
    studentDB.push_back(newStudent);
}

char generateOptions() {
    char options;
    cout << "a: Add a new student to the database." << endl;
    cout << "b: Display all students in the database." << endl;
    cout << "c. Find a student." << endl;
    cout << "d: Exit the program." << endl;
    cout << "Enter the options: ";
    cin >> options;
    return options;
};

void generateBanner() {
    cout << "---------------------------------------------------------------\n";
    cout << "|                     Student Database System                 |\n";
    cout << "---------------------------------------------------------------\n";
}

void displayStudents(vector<Student> &studentDB) {
    if(studentDB.size() == 0) {
        cout << "No Student(s) in database" << endl;
        return;
    }
    vector<Student>::iterator studentIterator;
    for(studentIterator = studentDB.begin(); studentIterator != studentDB.end(); studentIterator++) {
        displayStudentTemplete(&*studentIterator);
    }
};

void displayStudentTemplete(Student* student) {
    cout << "Student Information <" << student->getName() << ">" << endl;
    cout << "- Identifier: #" << student->getId() << endl;
    cout << "- Name: " << student->getName() << endl;
    cout << "- Grade: " << student->getGrade() << endl;
    cout << endl;
}

void findStudent(vector<Student> &studentDB, int id) {
    for(auto& student : studentDB) {
        if(student.getId() == id) {
            return displayStudentTemplete(&student);
        }
    }
    cout << "Could not find the student with Id: " << id << endl;
};
