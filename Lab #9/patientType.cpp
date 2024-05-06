//
//  patientType.cpp
//  Lab #9
//
//  Created by Bi Rong Liu on 5/4/24.
//

#include "patientType.hpp"

patientType::patientType(int patientId, int age, dateType dob = dateType(), doctorType attendingPhysician = doctorType(), dateType admitDate = dateType(), dateType dischargeDate = dateType()) : personType("", ""), patientId(patientId), age(age), dob(dob), attendingPhysician(attendingPhysician), admitDate(admitDate), dischargeDate(dischargeDate) {}

void patientType::setPatientID(int patientId) {
    this->patientId = patientId;
}

dateType patientType::getDischargeDate() {
    return dischargeDate;
}

void patientType::setDischargeDate(dateType dischargeDate) {
    this->dischargeDate = dischargeDate;
}

void patientType::setAdmitDate(dateType dischargeDate) {
    this->dischargeDate = dischargeDate;
}

dateType patientType::getAdmitDate() {
    return this->admitDate;
}

doctorType patientType::getAttendingPhysician() {
    return attendingPhysician;
}

void patientType::setAttendingPhysician(doctorType attendingPhysician) {
    this->attendingPhysician = attendingPhysician;
}

int patientType::getId() {
    return this->patientId;
}

void patientType::setAge(int age) {
    this->age = age;
}

int patientType::getAge() {
    return this->age;
}

void patientType::setDOB(dateType dob) {
    this->dob = dob;
}

dateType patientType::getDOB() {
    return this->dob;
}
