//
//  vector2D.h
//  Rita
//
//  Created by Paul Diaz on 12/12/14.
//  Copyright (c) 2014 Paul Diaz. All rights reserved.
//

#ifndef Rita_vector2D_h
#define Rita_vector2D_h
/* Vector2D.h */

class Vector2D {
    
public:
    Vector2D() : x(0), y(0) {};					// default constructor
    Vector2D(double, double);					// parameterized constructor
    double magnitude()	const;					// returns magnitude
    void print() const;				// prints vector in x(iHat) + y(jHat) form
    
    /* overloaded operators */
    const Vector2D operator +(const Vector2D &b);	// vector addition
    const Vector2D operator -(const Vector2D &b);	// vector subtraction
    bool operator ==(const Vector2D &b);			// equivalency, components equal?
    bool operator !=(const Vector2D &b);			// not equivalent, components not equal?
    bool operator >(const Vector2D &b);				// true for: |A| > |B|
    bool operator <(const Vector2D &b);				// true for: |A| < |B|
    double operator *(const Vector2D &b);			// dot product
    
    /* overloaded unary operators */
    const Vector2D operator -(void) const;		// negation: returns object that has the
    // the negative components of the operand
    
private:
    double x, y;								// components x and y
};

#endif
