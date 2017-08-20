//
//  QueueException.cpp
//  Kaya
//
//  Created by Paul Williams Diaz on 3/23/14.
//  Copyright (c) 2014 Paul Williams Diaz. All rights reserved.
//

#include "QueueException.h"
using namespace std;

QueueException::QueueException(string message){
    error = message;
}

string QueueException::getError()const{
    return error;
}
