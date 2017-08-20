//
//  QueueException.h
//  Kaya
//
//  Created by Paul Williams Diaz on 3/23/14.
//  Copyright (c) 2014 Paul Williams Diaz. All rights reserved.
//

#ifndef __Kaya__QueueException__
#define __Kaya__QueueException__
#include <iostream>
#include <string>

using namespace std;

class QueueException{
public:
    QueueException(string message);
    string getError() const;
    ~QueueException(){}
private:
    string error;
};

#endif /* defined(__Kaya__QueueException__) */
