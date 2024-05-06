//
//  patientType.hpp
//  Lab #9
//
//  Created by Bi Rong Liu on 5/4/24.
//
/**
 Design the class patientType, inherited from the class personType, with additional data members to store a patient’s ID, age, date of birth, attending physician’s name, the date when the patient was admitted in the hospital, and the date when the patient was discharged from the hospital. (Use the class dateType to store the date of birth, admit date, discharge date, and the class doctorType to store the attending physician’s name.) Add appropriate constructors and member functions to initialize, access, and manipulate the data members. (constructors, setters, getters)
 
 */
#ifndef patientType_hpp
#define patientType_hpp

#include "personType.hpp"
#include "doctorType.hpp"
#include "dateType.hpp"
#include <string>

class patientType : public personType {
private:
    int patientId;
    int age;
    dateType dob;
    doctorType attendingPhysician;
    dateType admitDate;
    dateType dischargeDate;

public:
    patientType(int patientId, int age, dateType dob, doctorType attendingPhysician, dateType admitDate, dateType dischargeDate);
    
    void setPatientID(int patientId);
    int getId();

    void setAge(int age);
    int getAge();

    void setDOB(dateType dob);
    dateType getDOB();

    void setAttendingPhysician(doctorType attendingPhysician);
    doctorType getAttendingPhysician();

    void setAdmitDate(dateType admitDate);
    dateType getAdmitDate();

    void setDischargeDate(dateType dischargeDate);
    dateType getDischargeDate();

};

#endif
