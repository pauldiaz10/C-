//Paul Williams Diaz
//pauldiaz@my.smccd.edu
//Project 7 - Chained Hash Table
//C++ Data Structures
//Prof. Stacey Grasso
//05/6/14

#include <cstdlib>    // Provides size_t
#include "node2.cpp"    // Provides the node type, from Figure 6.5 on page 306
#include <iostream>

using namespace std;

const std::size_t TABLE_SIZE = 811;

template <class RecordType>
class table
{
public:
    // CONSTRUCTORS AND DESTRUCTOR
    table( );
    table(const table& source);
    ~table( );
    // MODIFICATION MEMBER FUNCTIONS
    void insert(const RecordType& entry);
    void remove(int key);
    void operator =(const table& source);
    // CONSTANT MEMBER FUNCTIONS
    void find(int key, bool& found, RecordType& result) const;
    bool is_present(int key) const;
    std::size_t size( ) const { return total_records; }
    
    //function to print the table
    void printTable();
 
private:
    node<RecordType> *data[TABLE_SIZE];
    std::size_t total_records;
    
    // HELPER MEMBER FUNCTION
    std::size_t hash(int key) const;
};


// CONSTRUCTOR for the Table<RecordType> template class:
// Postcondition: The Table has been initialized as an empty Table.
template <class RecordType>
table<RecordType>::table(){
    
    for(std::size_t i = 0; i < TABLE_SIZE; i++){
        data[i] = NULL;
    }
    total_records = 0;
}

//copy constructor
template <class RecordType>
table<RecordType>::table(const table& source){
    total_records = source.total_records;
    
    for(std::size_t i = 0; i < TABLE_SIZE; i++){//goes to all heads/array
        node<RecordType> *cursor = source.data[i];
        
        while (cursor != NULL){
            cursor = cursor->link();
        }
        list_copy(source.data[i], data[i], cursor);
    }
}

//overload =operator
//similar to copy constructor
template <class RecordType>
void table<RecordType>::operator=(const table& source){
    if(this != &source){
        
        total_records = source.total_records;
        
        for(std::size_t i = 0; i < TABLE_SIZE; i++){
            node<RecordType> *cursor = data[i];
            
            while(cursor != NULL){
                cursor = cursor->link();
            }
            list_copy(source.data[i], data[i], cursor);
        }
    }
}

template <class RecordType>
table<RecordType>::~table(){
    for(std::size_t i = 0; i < TABLE_SIZE; i++){//go through the array, then
        node<RecordType> *entry = data[i];//each element(head of linked list)
        list_clear(entry);//will be cleared using list_clear() in the node2 class
    }
}


template <class RecordType>
std::size_t table<RecordType>::hash(int key) const {
    return key % TABLE_SIZE;
}

// Precondition: entry.key >= 0. Also if entry.key is not already a key in
// the table, then the Table has space for another record
// (i.e., size( ) < CAPACITY).
// Postcondition: If the table already had a record with a key equal to
// entry.key, then that record is replaced by entry. Otherwise, entry has
// been added as a new record of the Table.
template <class RecordType>
void table<RecordType>::insert(const RecordType& entry){

    std::size_t index = hash(entry.getPhone());
    node<RecordType> *cursor = data[index];
    
    if(cursor == NULL){//if it's NULL, then
        list_head_insert(data[index], entry);//we insert the new entry as the first node
    }else{                                  //otherwise, we call list_insert(node, entry)
        list_insert(data[index], entry);//this function goes through the list and insert the new
    }                                   //entry at the end
    total_records++;
}

// Postcondition: If a record was in the Table with the specified key, then
// that record has been removed; otherwise the table is unchanged.
template <class RecordType>
void table<RecordType>::remove(int key){
    std::size_t index = hash(key);
    node<RecordType> *cursor = data[index];
    node<RecordType> *prev = NULL;
    int count = 0;
    
    if(cursor == NULL){//if the list is NULL, then we can't perform remove function
        std::cout << key << " is not found." << endl;
        return;
    }else{
        while(cursor != NULL && cursor->data().getPhone() != key){//we go though the list until we reach
            count++;                                //the end of the list && when we find it, then we stop
            prev = cursor;                          //traversing. 
            cursor = cursor->link();
        }

        if(count == 0){                 //if count is 0, it means that there's only 1 node in the list, then
            list_head_remove(data[index]);//we just remove the head node
            std::cout << "\n" << "Success!" << endl;
        }else{                          //otherwise, we call remove to do the work
            list_remove(prev);      //list_remove(node); removes the node after node *prev
            std::cout << "\n" << "Success!" << endl;
        }
    }
}

// Postcondition: The return value is true if there is a record in the
// Table with the specified key. Otherwise, the return value is false.
template <class RecordType>
bool table<RecordType>::is_present(int key) const{
    
    std::size_t index = hash(key);
    node<RecordType> *cursor = data[index];
    bool present = false;
    
    while(cursor != NULL){//we go through the list
        if(cursor->data().getPhone() == key){//and checks each node if key is equal to the node's key.
            present = true; //if they are equal then we found it.
        }
        cursor = cursor->link();
    }
    return present;
}

// Postcondition: If a record is in the Table with the specified key, then
// found is true and result is set to a copy of the record with that key.
// Otherwise found is false and the result contains garbage.
template <class RecordType>
void table<RecordType>::find(int key, bool& found, RecordType& result) const{
    
    std::size_t index = hash(key);
    node<RecordType> *cursor = data[index];
    found = false;
    
    while(cursor != NULL){//we go through the list
        if(cursor->data().getPhone() == key){//and checks each node if key is equal to the node's key.
            result = cursor->data();//if we find it, then we initialize variable result to give a value
            found = true;//as well as the variable found (pass-by-reference)
        }
        cursor = cursor->link();
    }
}

//A function to print the table
template <class RecordType>
void table<RecordType>::printTable(){
    
    for(std::size_t i = 0; i < TABLE_SIZE; i++){
        if(data[i] != NULL){
            node<RecordType> *cursor = data[i];
            
            while(cursor != NULL){
                std::cout << "---------------------" <<endl;
                std::cout << "Index: " << i << endl;
                std::cout << cursor->data().getName() << endl;
                std::cout << cursor->data().getAddress() << endl;
                std::cout << cursor->data().getPhone() << endl;
                std::cout << "---------------------" <<endl;
                cursor = cursor->link();
            }
        }
    }
}




