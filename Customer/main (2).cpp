//Paul Williams Diaz
//pauldiaz@my.smccd.edu
//Project 7 - Chained Hash Table
//C++ Data Structures
//Prof. Stacey Grasso
//05/6/14

#include <iostream>
#include "table.h"
#include "Customer.h"

using namespace std;

int main(){
    std::cout << "--------WELCOME--------" << endl;
    std::cout << "   SQUARE CHAIR PIZZA\n" << endl;
    //Write an application which can be used by Square Chair Pizza to store Customer info.  This application will store all Customer objects in a hash table, and provide the following functionality:
    
    //a new Customer can be entered;  user first provides the Customer name, phone number and address
    //an existing Customer’s record can be retrieved ;  user provides the phone number
    //a Customer can be deleted;  user provides the phone number
    table<Customer> table;
    int task;
    
    do{
        std::cout << "Enter 1 to store a customer." << endl;
        std::cout << "Enter 2 to retreive a customer infor." << endl;
        std::cout << "Enter 3 to delete a customer." << endl;
        std::cout << "Enter 0 to exit this program: ";
        std::cin >> task;
        
        switch (task){
            //a new Customer can be entered; user first provides the Customer name, phone and address
            case 1:{
                string name;
                string address;
                std::size_t phonecase1;
                
                std::cout << endl;
                std::cout << "Enter name: ";
                std::cin >> name;
                
                std::cout << "Enter phone: ";
                std::cin >> phonecase1;
                
                std::cout << "Enter address: ";
                std::cin >> address;
                
                Customer cust(name, address, phonecase1);
                table.insert(cust);
                
                std::cout << endl;
            }
                break;
                
            //an existing Customer’s record can be retrieved ; user provides the phone
            case 2:{
                std::size_t phonecase2;
                std::cout << endl;
                std::cout << "Enter phone: ";
                std::cin >> phonecase2;
                std::cout << endl;
                
                bool found;
                Customer customerFind;
                
                table.find(phonecase2, found, customerFind);
                
                if(!found){
                    std::cout << "\nCustomer doens't exist." << endl;
                }else{
                    std::cout << customerFind << endl;
                }
                std::cout << endl;
            }
                break;
                
                //a Customer can be deleted; user provides the phone
            case 3:{
                std::size_t phonecase3;
                std::cout << endl;
                std::cout << "Enter phone: ";
                std::cin >> phonecase3;
                
                if(table.is_present(phonecase3)){
                    table.remove(phonecase3);
                }else{
                    std::cout << "\nCustomer doens't exist." << endl;
                }
                std::cout << endl;
            }
                break;
        }
    }while(task != 0);

    std::cout << "\nThank you." << endl;
    std::cout << "Programmed by: Paul Diaz" << endl;
    return 0;
}