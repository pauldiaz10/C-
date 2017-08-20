#include<iostream>
#include"PlaneFlight.h"

using namespace std;

PlaneFlight::PlaneFlight()
{
	cap = SIZE;
	seats = new int[cap];
	count = 0;
	//initialize all seats to empty
	for(int index = 0; index < cap; index++)
	{
		seats[index] = 0;
	}
}//PlaneFlight

PlaneFlight::PlaneFlight(int capacity)
{
	seats = new int[capacity];
	count = 0;
	cap = capacity;
	//initialize all seats to empty
	for(int index = 0; index < capacity; index++)
	{
		seats[index] = 0;
	}
}
//add copyConstructor

PlaneFlight::PlaneFlight(const PlaneFlight& obj)
{
    
	cout << "in copy constructor\n";
	if(this != &obj)
	{
		count = obj.count;
		cap = obj.cap;
		seats = new int[cap];
		for(int i = 0; i < cap; i++)
		{
			seats[i] = obj.seats[i];
		}
		//return *this;
	}
}


/*effect: determine if all seats are full
 *returns: true if all seats are full. false otherwise
 */
bool PlaneFlight::isFull() const
{
	return count == cap;
}//isFull

/*effect: dertermine if all sears are empty
 *return: true if all seats are empty; false otherwise
 */
bool PlaneFlight::isEmpty() const
{
	return count == 0;
}

int PlaneFlight::getCapacity() const
{
	return cap;
}
int PlaneFlight::getCount() const
{
	return count;
}


/*effect: determine if seatNo is a avaiable seat or not
 *return: true avaiable; otherwise false
 *precondtion--seatNo is valid number
 */
bool PlaneFlight::seatVacant(int seatNo) const
{
	if(validSeatNum(seatNo))
	{
		if(seats[seatNo] == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
    
	return seats[seatNo] == 0;
}


void PlaneFlight::reserveSeat(int seatNo)
{
	if(validSeatNum(seatNo))
	{
		if(seats[seatNo] == 1)
		{
			cout << "already taken\n";
			cout << count;
		}
		else
		{
			seats[seatNo] = 1;
			count++;
			cout << "reservation success!\n";
			//cout << "seats["<< seatNo << "] = " << seats[seatNo] << "\n";
        }
	}
	else
	{
		cout << "\nbecause of invaild seatNo, cannot make reserve a seat\n";
	}
}

/*effect: cancel(unreserve) a seat numbered seatNo
 *return: no
 *precondtion- seatNo is valid
 *postcondtion- seatNo is now available
 */
void PlaneFlight::cancelSeat(int seatNo)
{
	if(validSeatNum(seatNo) && seats[seatNo] == 1)
	{
		//cout << "found canceled seat ";
		seats[seatNo] = 0;
		count--;
		cout << "cancelation success!\n";
		//cout << "seats[seatNo] = " << seats[seatNo] <<"\n";
	}
	else
	{
		cout << "not cancel";
	}
}

/*effect: determine if seatNo is a valid number or not
 *return true if seatNo is a valid number; otherwise false
 */
bool PlaneFlight::validSeatNum(int seatNo)const
{
	return seatNo >= 0 && seatNo < cap;
}

ostream& operator<<(ostream& out, const PlaneFlight& obj )
{
	out << "\n---Seats Info---\n";
	for(int i = 0; i < obj.cap; i++)
	{
		if(obj.seats[i] == 0)
		{
			out << i << " : empty\n";
		}
		else if(obj.seats[i] == 1)
		{
			out << i << " : taken\n";
		}
		else
		{
			cout << "Error\n";
		}
        
	}
	out << " ";
    
	return out ;
}

PlaneFlight::~PlaneFlight()
{
	delete [] seats;
}

/*
 operator=
 Expression --- a @ b
 Function member --- A::operator@(B)
 Not Global function
 *where a is an object of classA, b is an object of class B*
 */
PlaneFlight& PlaneFlight::operator=(const PlaneFlight& obj)
{
	if(this != &obj)//inorder to avoid to delete caller itself
	{
		count = obj.count;
		cap = obj.cap;
        
		delete[] seats;
		seats = new int[cap];
        
		for(int i = 0; i < count; i++)
		{
			seats[i] = obj.seats[i];
		}
		return *this;//the reason why we retrun *this(this pointer)
        //is make TWO objects refer to the same object!
	}
}