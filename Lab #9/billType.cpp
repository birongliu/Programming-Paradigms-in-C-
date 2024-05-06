//
//  billType.cpp
//  Lab #9
//
//  Created by Bi Rong Liu on 5/4/24.
//

#include "billType.hpp"
#include "string"
using namespace std;

billType::billType(int id, Types type, long double cost) {
    this->id = id;
    this->type = type;
    this->cost = cost;
}

long double billType::getCost() const {
    return cost;
}

int billType::getId() const {
    return id;
}

string billType::getType() const {
    switch (type) {
        case MEDICINE: return "medicine";
        case DOCTOR: return "doctor";
        case ROOM: return "room";
        default: return "N/A";
    }
};

void billType::setId(int id) {
    this->id = id;
}


void billType::setType(Types type){
    this->type = type;
};

void billType::setCost(long double cost) {
    this->cost = cost;
};

Types billType::convert(int type) {
    switch (type) {
        case 0: return MEDICINE;
        case 1: return DOCTOR;
        case 2: return ROOM;
        default: return NONE;
    }
}
