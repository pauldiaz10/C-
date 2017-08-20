//
//  main.cpp
//  Kaya
//
//  Created by Paul Williams Diaz on 1/19/14.
//  Copyright (c) 2014 Paul Williams Diaz. All rights reserved.
//



#include "EightSideDie.h"
#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
    std::cout << "hello";
	printf("Hello!\n");
	EightSideDie die1;
    
    
	for(int i = 0; i < 10; i++ )
	{
		die1.getSideCount(i);
	}
    
    cout << "\nDie1: " << die1 << " ";
    
	// << die1;
	//die1.print();
    
	printf("\nEnd!\n");
    
	return 0;
}

