//
//  billType.hpp
//  Lab #9
//
//  Created by Bi Rong Liu on 5/4/24.
//

#ifndef billType_hpp
#define billType_hpp

#include <stdio.h>
#include "string"
using namespace std;

typedef enum {
    MEDICINE,
    DOCTOR,
    ROOM,
    NONE
} Types;

class billType {
    int id;
    Types type;
    long double cost;
    
public:
    billType(int id, Types type, long double cost);
    long double getCost() const;
    int getId() const;
    string getType() const;
    void setCost(long double cost);
    void setType(Types type);
    void setId(int id);
    
    static Types convert(int type);
};

#endif /* billType_hpp */
