//
//  EightSideDie.h
//  Kaya
//
//  Created by Paul Williams Diaz on 1/19/14.
//  Copyright (c) 2014 Paul Williams Diaz. All rights reserved.
//

#ifndef Kaya_EightSideDie_h
#define Kaya_EightSideDie_h

//EightSideDie.h
#include<ostream>

using namespace std;

class EightSideDie
{
public:
    EightSideDie();
    EightSideDie(const EightSideDie& aDie);
    
    void roll();
    int getCurrent() const;
    int getSideCount(int num) const;
    bool validCount(int num) const;
    static EightSideDie addAll(const EightSideDie& aDie, const EightSideDie& aDie2);
    int largest() const;
    bool operator== (const EightSideDie& obj);
    friend ostream& operator<<(ostream& out, const EightSideDie& aDie);
    void reset();
    
    void print();
    
private:
    int counts[9];
    int recentFace; 
};










#endif
