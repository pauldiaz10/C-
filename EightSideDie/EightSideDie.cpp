//
//  EightSideDie.cpp
//  Kaya
//
//  Created by Paul Williams Diaz on 1/19/14.
//  Copyright (c) 2014 Paul Williams Diaz. All rights reserved.
//

#include "EightSideDie.h"

//EightSideDie.cpp

#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#include "EightSideDie.h"

EightSideDie::EightSideDie()
{
	cout << "constractor";
	recentFace = 0;
	counts[9];
	for(int i = 0; i < 9; i++)
	{
		counts[i] = 0;
	}
}
EightSideDie::EightSideDie(const EightSideDie& aDie)
{
	recentFace = aDie.recentFace;
	for(int index = 0; index < 9; index++)
	{
		counts[index] = aDie.counts[index];
	}
    
}
void EightSideDie::roll()
{
	recentFace = rand()%8+1;
	counts[recentFace]++;
    
	printf("Face is %d \n", recentFace);
}
int EightSideDie::getCurrent()const
{
	return recentFace;
}
int EightSideDie::getSideCount(int num)const
{//const
	int rolledTimes = 0;
	rolledTimes = counts[num];
	return rolledTimes;
}

bool EightSideDie::validCount(int num)const
{
	bool validity = false;
	if(num < 0 and num > 9)
	{
		printf("invalid counts\n");
	}
	else
	{
		printf("valid counts\n");
		validity = true;
	}
	return validity;
}
EightSideDie EightSideDie::addAll(const EightSideDie& aDie1, const EightSideDie& aDie2)
{
	EightSideDie added;
	for(int index = 1; index <= 9; index++)
	{
		added.counts[index] = aDie1.counts[index]+ aDie2.counts[index];
	}
    
	return added;
}

int EightSideDie::largest()const
{
	int largest = 0;
	for(int index = 1; index <= 9; index++)
	{
		if(largest < counts[index])
		{
			largest = counts[index];
		}
	}
    return largest;
}

bool EightSideDie::operator==(const EightSideDie& obj)
{
	bool equal = false;
	if(recentFace == obj.recentFace)
	{
		for(int i = 1; i <= 9; i++)
		{
			if(counts[i] != obj.counts[i])
			{
				return equal =false;
			}
            
		}
        
	}
	else
	{
		return equal = false;
	}
}

ostream& operator<<(ostream& out, const EightSideDie& aDie)
{
	//printf("this is operator!");
	//out << "How are you?";
	/*
     out << "---Eight Side Die info---\n";
     for(int index = 1; index <= 9;index++)
     {
     out << " face " << index << " th = " << aDie.counts[index] << "\n";
     }
     out << "your most recent face is " << recentFace << "\n";
     return out
     */
    
    for(int i = 1; i < 9; i++){
        out << aDie.counts[i] << " ";
    }
    return out;
}
/*void EightSideDie::print()
{
	cout << "---Eight Side Die info---\n";
	for(int index = 1; index <= 9;index++)
	{
		//cout << " face " << index << " th = " << aDie.counts[index] << "\n";
	}
	cout  << "your most recent face is " << recentFace << "\n";
	
}*/
void EightSideDie::reset()
{
	recentFace = 0;
	for(int i = 1; i <= 9; i++)
	{
		counts[i] = 0;
	}
}




