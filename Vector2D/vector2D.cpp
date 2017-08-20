//
//  vector2D.cpp
//  Rita
//
//  Created by Paul Diaz on 12/12/14.
//  Copyright (c) 2014 Paul Diaz. All rights reserved.
//

#include "vector2D.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* Parameterized Constructor */
Vector2D::Vector2D(double xComp, double yComp) {
    x = xComp;
    y = yComp;
}

/* Magnitude */
double Vector2D::magnitude() const {
    return sqrt(pow(x, 2) + pow(y, 2));
}

/* Print */
void Vector2D::print() const {
    
    char iHat = 140;			// ascii code for iHat
    // no ascii for jHat ... :(
    
    cout << x << iHat;			// print x component with iHat
    
    /* correct for sign on y component */
    if (y > 0) {
        cout << " + " << y;
    }
    else {
        cout << " - " << abs(y);
    }
    cout << "j^" << endl;		// print "jHat"
}

/* Overloaded Operators */
// Addition
const Vector2D Vector2D::operator +(const Vector2D &b) {
    return Vector2D(x + b.x, y + b.y);
}
// Subtraction
const Vector2D Vector2D::operator -(const Vector2D &b) {
    return Vector2D(x - b.x, y - b.y);
}
// Equivalency
bool Vector2D::operator ==(const Vector2D &b) {
    return (x == b.x && y == b.y);
}
// Non-equivalency
bool Vector2D::operator !=(const Vector2D &b) {
    return (x != b.x || y != b.y);
}
// Greater than
bool Vector2D::operator >(const Vector2D &b) {
    return ( this->magnitude() > b.magnitude() );
}
// Less than
bool Vector2D::operator <(const Vector2D &b) {
    return ( this->magnitude() < b.magnitude() );
}
// Dot product
double Vector2D::operator *(const Vector2D &b) {
    return ( x*b.x + y*b.y );
}
// Negation
const Vector2D Vector2D::operator -(void) const {
    return Vector2D(-x, -y);
}
