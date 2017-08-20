#include "StackException.h"
#include <iostream>
#include <list>
using namespace std;

template <class T>
class GStack
{
public:
	GStack();
	bool isEmpty() const;
	void push(const T& newItem) throw (StackException);
	T pop() throw (StackException);
	void pop(T& stackTop) throw (StackException);
	void getTop(T& stackTop) const throw (StackException);
	//~GStack();
	/* data */
private:
	list<T> top;
};

template <class T>
GStack<T>::GStack(){
	list<T> top = NULL;
}

template <class T>
bool GStack<T>::isEmpty() const
{
	//if(top.isEmpty()) again you can't do this isEmpty is basically you're calling this function which doesn't make any sense. You have to use empty() in the class list in the library, something like...
	if(top.empty()){
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
void GStack<T>::push(const T& newItem) throw (StackException)
{
    top.push_front(newItem);
    
    //also you have to code something that will check if whatever you are pushing
    //was successfully pushed in the stack, if it fails then you have to throw an
    //Exception
    
}

template <class T>
T GStack<T>::pop() throw (StackException){//here I changed void to T as a return type, I think this is where we really want to return something.
    T temp;
	if(isEmpty())
	{
		//cout << "stack is empty";
		//return;
        //I commented these 2 lines above, instead you throw an Exception if the
        //stack is empty
        throw StackException("Stack is empty.");
	}
	else
	{
        //also you have to create a T temp so you can return the one that you are
        //popping
        temp = top.front();
        top.pop_front();
	}
    //then dont' forget to return something
    return temp;
}

template <class T>
void GStack<T>::pop(T& stackTop) throw (StackException)
{
	//if(top.isempty()), be careful with your syntax
	if(isEmpty())
    {
		throw StackException("Stack is empty.");
	}
	else
	{
		//stackTop = top.pop_front();, again this doesn't return anything, so you can't do this./
        //this is a compilation error. use this instead...
        stackTop = top.front();
        //then now you can pop it
        top.pop_front();
	}
}
template <class T>
void GStack<T>::getTop(T& stackTop) const throw (StackException)
{
	
    //if (top.isempty()), no something function exists (isempty())
    if(isEmpty())
    {
        //throw "Stack is empty";
        throw StackException("Stack is empty.");
    }
    else
    {
        stackTop = top.front();
    }
}


