//
//  JetBlue.h
//  PlaneKaya
//
//  Created by Paul Williams Diaz on 4/20/13.
//  Copyright (c) 2013 Paul Williams Diaz. All rights reserved.
//

#ifndef __PlaneKaya__JetBlue__
#define __PlaneKaya__JetBlue__

#include <iostream>

#include"PlaneFlight.h"

class JetBlue:public PlaneFlight
{
public:
    JetBlue();
    JetBlue(int capacity);
    
    int seatsLeft() const;
    int furthestFront() const;
    int furthestRear() const;
    
};
#endif /* defined(__PlaneKaya__JetBlue__) */
