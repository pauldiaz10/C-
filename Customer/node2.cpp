//Paul Williams Diaz
//pauldiaz@my.smccd.edu
//Project 7 - Chained Hash Table
//C++ Data Structures
//Prof. Stacey Grasso
//05/6/14

#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
#include "node2.h"

// Precondition: head_ptr is the head pointer of a linked list.
// Postcondition: All nodes of the list have been returned to the heap,
// and the head_ptr is now NULL.
template <class Item>
void list_clear(node<Item>*& head_ptr){
	while (head_ptr != NULL)
	    list_head_remove(head_ptr);
}

// Precondition: source_ptr is the head pointer of a linked list.
// Postcondition: head_ptr and tail_ptr are the head and tail pointers for
// a new list that contains the same items as the list pointed to by
// source_ptr. The original list is unaltered.
template <class Item>
void list_copy(
               const node<Item>* source_ptr,
                     node<Item>*& head_ptr,
                     node<Item>*& tail_ptr){
	head_ptr = NULL;
	tail_ptr = NULL;
    
	// Handle the case of the empty list
	if (source_ptr == NULL)
	    return;
    
	// Make the head node for the newly created list, and put data in it
	list_head_insert(head_ptr, source_ptr->data( ));
	tail_ptr = head_ptr;
	
	// Copy rest of the nodes one at a time, adding at the tail of new list
	source_ptr = source_ptr->link( );
    while (source_ptr != NULL)
	{
	    list_insert(tail_ptr, source_ptr->data( ));
	    tail_ptr = tail_ptr->link( );
	    source_ptr = source_ptr->link( );
	}
}

// Precondition: head_ptr is the head pointer of a linked list.
// Postcondition: A new node containing the given entry has been added at
// the head of the linked list; head_ptr now points to the head of the new,
// longer linked list.
template <class Item>
void list_head_insert(node<Item>*& head_ptr, const Item& entry){
	head_ptr = new node<Item>(entry, head_ptr);
}

// Precondition: previous_ptr points to a node in a linked list.
// Postcondition: A new node containing the given entry has been added
// after the node that previous_ptr points to.
template <class Item>
void list_insert(node<Item>* previous_ptr, const Item& entry){
	node<Item> *insert_ptr;
    
	insert_ptr = new node<Item>(entry, previous_ptr->link( ));
	previous_ptr->set_link(insert_ptr);
}

// Precondition: head_ptr is the head pointer of a linked list, with at
// least one node.
// Postcondition: The head node has been removed and returned to the heap;
// head_ptr is now the head pointer of the new, shorter linked list.
template <class Item>
void list_head_remove(node<Item>*& head_ptr){
	node<Item> *remove_ptr;
    
	remove_ptr = head_ptr;
	head_ptr = head_ptr->link( );
	delete remove_ptr;
}

// Precondition: previous_ptr points to a node in a linked list, and this
// is not the tail node of the list.
// Postcondition: The node after previous_ptr has been removed from the
// linked list.
template <class Item>
void list_remove(node<Item>* previous_ptr){
	node<Item> *remove_ptr;
    
	remove_ptr = previous_ptr->link( );
	previous_ptr->set_link(remove_ptr->link( ));
	delete remove_ptr;
}

// Precondition: head_ptr is the head pointer of a linked list.
// Postcondition: The value returned is the number of nodes in the linked
// list.
template <class Item>
std::size_t list_length(const node<Item>* head_ptr){
	const node<Item> *cursor;
	std::size_t answer;
	
	answer = 0;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    ++answer;
	
	return answer;
}

// Precondition: head_ptr is the head pointer of a linked list, and
// position > 0.
// Postcondition: The return value is a pointer that points to the node at
// the specified position in the list. (The head node is position 1, the
// next node is position 2, and so on). If there is no such position, then
//  the null pointer is returned.
template <class NodePtr, class SizeType>
NodePtr list_locate(NodePtr head_ptr, SizeType position){
	NodePtr cursor;
	SizeType i;
    
	assert(0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != NULL); ++i)
	    cursor = cursor->link( );
	return cursor;
}

// Precondition: head_ptr is the head pointer of a linked list.
// Postcondition: The return value is a pointer that points to the first
// node containing the specified target in its data member. If there is no
// such node, the null pointer is returned.
template <class NodePtr, class Item>
NodePtr list_search(NodePtr head_ptr, const Item& target){
	NodePtr cursor;
	
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    if (target == cursor->data( ))
            return cursor;
	return NULL;
}


