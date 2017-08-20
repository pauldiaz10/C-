//Paul Williams Diaz
//pauldiaz@my.smccd.edu
//Project 7 - Chained Hash Table
//C++ Data Structures
//Prof. Stacey Grasso
//05/6/14

#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
#include <iostream>
using namespace std;

class Customer{
public:
    Customer(){
        setPhoneNum(0);
    }
    //constructor which accepts a name, address, and a phone number 
    Customer(string n, string a, int p){
        name = n;
        address = a;
        phoneNum = p;
    }
    
    //copy constructor for this class
    Customer(const Customer& cust){
        name = cust.name;
        address = cust.address;
        phoneNum = cust.phoneNum;
    }
    
    //Provide set and get functions for each piece of instance data.
    string getName()const{return name;}
    string getAddress()const{return address;}
    int getPhone()const{return phoneNum;}
    
    void setName(string n){name = n;}
    void setAddress(string a){address = a;}
    void setPhoneNum(int p){ phoneNum = p;}
    
    //Overload the assignment operator:
    Customer& operator=(const Customer& cust){
        if(this != &cust){
            name = cust.name;
            address = cust.address;
            phoneNum = cust.phoneNum;
        }
        return *this;
    }
    
    //string representation for a Customer
    friend ostream& operator<<(ostream& out, const Customer& obj){
        if(obj.getPhone() == 0){
            out << "";
        }else{
            out << "Name:    " << obj.getName() << "\nAddress: " << obj.getAddress() << "\nPhone:   " <<
                obj.getPhone() << endl;
        }
        return out;
    }
private:
    string name;
    string address;
    int phoneNum;
};
