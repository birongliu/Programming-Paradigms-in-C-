//
//  main.cpp
//  Lab #9
//
//  Created by Bi Rong Liu on 5/1/24.
//

#include <iostream>
#include "billType.hpp"
#include "doctorType.hpp"
#include "patientType.hpp"
#include "array"
#include <fstream>
#include "vector"

/*
In this exercise, you will design various classes and write a program to computerize the billing system of a hospital.

Design the class doctorType, inherited from the class personType, with an additional data member to store a doctor’s speciality. Add appropriate constructors and member functions to initialize, access, and manipulate the data members. (constructors, setters, getters)

Design the class billType with data members to store a patient’s ID and a patient’s hospital charges, such as pharmacy charges for medicine, doctor’s fee, and room charges. Add appropriate constructors and member functions to initialize, access, and manipulate the data members. (constructors, setters, getters)


Design the class patientType, inherited from the class personType, with additional data members to store a patient’s ID, age, date of birth, attending physician’s name, the date when the patient was admitted in the hospital, and the date when the patient was discharged from the hospital. (Use the class dateType to store the date of birth, admit date, discharge date, and the class doctorType to store the attending physician’s name.) Add appropriate constructors and member functions to initialize, access, and manipulate the data members. (constructors, setters, getters)


Write a program to test your classes.
*/
void generateBanner();
patientType generatePatientInfo();
doctorType generatePatientDoctorInfo();
dateType generateDate(string k);
billType generateBillInfo();
void generateSearch();
int generateId();
char generateOptions();
#define SIZE 2040
int counter = 0;
patientType *patients = (patientType*)malloc(sizeof(patientType) * SIZE);
int seqSearch(const patientType list[], int listLength, string searchItem);
int main(int argc, const char * argv[]) {
    generateBanner();
    char key = generateOptions();
    while(true) {
        if(key == 'b') break;
        if(key == 'c') {
            generatePatientInfo();
            generateBillInfo();
            cout << "Successfully created the billing and patient info\n";
        }
        if(key == 's') {
            generateSearch();
        }
        key = generateOptions();
    }
    
    return 0;
}

void generateBanner() {
    cout << "-----------------------------------------------------------------------------\n";
    cout << "|                       Hospital Billing System                             |\n";
    cout << "-----------------------------------------------------------------------------\n";
}

patientType generatePatientInfo() {
    string patientFirstName, patientLastName, patientDOB, patientAdmitDate, patientDischargeDate;
    int patientAge;
    cout << "\xe2\x9d\xaf Patient Information\n";
    cout << "\xe2\x9C\x94 Enter first name:";
    cin >> patientFirstName;
    
    cout << "\xe2\x9C\x94 Enter last name: ";
    cin >> patientLastName;
    
    cout << "\xe2\x9C\x94 Enter age: ";
    cin >> patientAge;
    
    cout << "\xe2\x9C\x94 Enter birthday (ex: 09/01/2021): ";
    cin >> patientDOB;
    
    cout << "\xe2\x9C\x94 Enter admitted date (ex: 09/01/2021): ";
    cin >> patientAdmitDate;
    
    cout << "\xe2\x9C\x94 Enter dicharge date (ex: 09/01/2021): ";
    cin >> patientDischargeDate;
    
    doctorType doc = generatePatientDoctorInfo();
    patientType k = patientType(generateId(), patientAge, generateDate(patientDOB), doc, generateDate(patientAdmitDate), generateDate(patientDischargeDate));
    k.setName(patientFirstName, patientLastName);
    patients[counter] = k;
    counter++;
    return k;
    
}

doctorType generatePatientDoctorInfo() {
    string speciality, firstName, lastName;
    cout << "\n\xe2\x9d\xaf Patient Doctor Information\n";
    cout << "\xe2\x9C\x94 Enter speciality: ";
    cin >> speciality;

    
    cout << "\xe2\x9C\x94 Enter first name: ";
    cin >> firstName;
    
    cout << "\xe2\x9C\x94 Enter last name: ";
    cin >> lastName;
    
    doctorType doctor = doctorType(speciality);
    doctor.setName(firstName, lastName);
    return doctor;
};

billType generateBillInfo() {
    int cost, type;
    cout << "\n\xe2\x9d\xaf Patient Bill Information\n";
    cout << "\xe2\x9C\x94 Enter the type of bill (0=MEDICINE|1=DOCTOR|2=ROOM): ";
    cin >> type;
    cout << "\xe2\x9C\x94 Enter the cost: ";
    cin >> cost;
    billType bill(generateId(), billType::convert(type), cost);
    return bill;
}
void generateSearch() {
    string name;
    cout << "Enter first name of the patients you want search for? ";
    cin >> name;
    while(name != "back") {
        int query = seqSearch(patients, SIZE, name);
        if(query != -1) {
            patientType result = patients[query];
            dateType discharge = result.getDischargeDate();
            dateType admit = result.getAdmitDate();
            cout << "Id: " << result.getId() << endl;
            cout << "lastName: " << result.getLastName() << endl;
            cout << "firstName: " << result.getFirstName() << endl;
            cout << "discharge Date: " << discharge.getMonth() << "/" << discharge.getDay() << "/" << discharge.getYear() << endl;
            cout << "Admit Date: " << admit.getMonth() << "/" << admit.getDay() << "/" << admit.getYear() << endl;
        }
        if(query == -1) {
            cout << "There is no patient named: " << name << endl;
        }
        if(name == "back") break;
        cout << "View another patients (patient name | back): ";
        cin >> name;
    
    }
}
dateType generateDate(string k) {
    int month = stoi(k.substr(0, k.find("/")));
    int day = stoi(k.substr(k.find("/") + 1, k.find("/")));
    int year = stoi(k.substr(k.find_first_of("/", 5) + 1));
    cout << "y=" << year << endl;
    
    return dateType(month, day, year);
}


int generateId() {
    srand(time(0));
    int random_variable = rand() % 9000 + 1000;
    return random_variable;
}

char generateOptions() {
    char options;
    cout << "c: create patient and billing records\ns: search for the patient by name\nb: exit the program\n";
    cout << "Select an options:";
    cin >> options;
    return options;
}

int seqSearch(const patientType list[], int listLength, string searchItem) {
    for(int i = 0; i < listLength; i++) {
        if(list[i].getFirstName() == searchItem) return i;
    }
    return -1;
}
