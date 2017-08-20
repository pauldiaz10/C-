//
//  StackException.cpp
//  Kaya
//
//  Created by Paul Williams Diaz on 3/23/14.
//  Copyright (c) 2014 Paul Williams Diaz. All rights reserved.
//

#include "StackException.h"

StackException::StackException(string message){
    error = message;
}

string StackException::getError()const{
    return error;
}