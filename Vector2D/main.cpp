//
//  main.cpp
//  Rita
//
//  Created by Paul Diaz on 12/12/14.
//  Copyright (c) 2014 Paul Diaz. All rights reserved.
//

/* main.cpp */

#include <iostream>
#include "vector2D.h"

using namespace std;

int main() {
    
    Vector2D A(2, 4), B(3, 4);
    
    Vector2D C;
    
    A.print();
    B.print();
    C.print();
    
    C = A + B;								// addition
    cout << "A + B = "; C.print();
    
    C = A - B;								// subtraction
    cout << "A - B = "; C.print();
    
    C = A;									// assign A to C
    if (C == A) {							// test equivalency
        cout << "C equals A\n";
    }
    else {
        cout << "C is not equal to A\n";
    }
    
    if (C != A) {							// test non-equivalency
        cout << "C equals A\n";
    }
    else {
        cout << "C is not equal to A\n";
    }
    
    if (A > B) {							// test greater than
        cout << "A is larger than B\n";
    }
    else {
        cout << "B is larger than A\n";
    }
    
    if (A < B) {
        cout << "A is smaller than B\n";
    }
    else {
        cout << "B is smaller than A\n";
    }
    
    C = -A;									// negation
    cout << "C is now -A: "; C.print();
    
    cout << "The dot product of A and B is: " << A*B << endl;
    
    //system("pause");
    return 1;
}
