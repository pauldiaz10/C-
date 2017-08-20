#include<iostream>
#include"JetBlue.h"
using namespace std;

int main()
{
	//JetBlue j1();
	//JetBlue j2(5);
    
	int capacity = 0;
	int action = 0;
	int seatNo = 0;
	cout << "enter capacity of the jet plane: ";
	cin >> capacity;
    
	JetBlue j2(capacity);
	do
	{
        cout << "\n";
		cout << "1: check the fullness of this plane\n";
		cout << "2: check the emptyness of this plane\n";
		cout << "3: reserve a seat\n";
		cout << "4: reserve the furthest fron seat\n";
		cout << "5: reserve the furthest rear seat\n";
		cout << "6: cancel a seat\n";
		cout << "7: show the current reservation\n";
		cout << "8: exit this program: ";
		cin >> action;
        
		switch(action)
		{
			case 1://isFull()
				if(j2.isFull())
				{
                    cout << "\n";
					cout << "Seats are Full\n";
				}
				else
				{
                    cout << "\n";
					cout << "Seats are not full\n";
				}
				break;
			case 2://isEmpty
				if(j2.isEmpty())
				{
                    cout << "\n";
					cout << "Seats is empty\n";
				}
				else
				{
                    cout << "\n";
					cout << "Seats is not Empty\n";
				}
				break;
			case 3:
				seatNo = 0;
				cout << "\nreserve a seat";
				cout << "\nenter the seat number: ";
				cin >> seatNo;
				j2.reserveSeat(seatNo);
				seatNo = 0;
                break;
                
			case 4:
                cout << "\n";
				cout << "reserve furthest front\n";
				cout << "Further front " << j2.furthestFront() << "\n";
				j2.reserveSeat(j2.furthestFront());
				break;
			case 5:
				cout << "\n";
				cout << "Further Rear " << j2.furthestRear() << "\n";
				j2.reserveSeat(j2.furthestRear());
				break;
			case 6:
                cout << "\n";
				cout << "cancel a seat: ";
				cin >> seatNo;
				j2.cancelSeat(seatNo);
				seatNo = 0;
				break;
			case 7:
                cout << "\n";
				cout << "---Plane Flight Information---\n";
				cout << j2;
				break;
			case 8:
                cout << "\n";
				cout << "Thank you\n";
				cout << "Programed by Kaya Ota";
				break;
                
		}//switch
	}while(action != 8);	
    
	return 0;
}