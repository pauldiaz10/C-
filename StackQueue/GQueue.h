#include <list>
#include "QueueException.h"

using namespace std;

template <class T>
class GQueue{
public:
    GQueue(){front(NULL);};
    bool isEmpty() const;
    void push(const T& newItem) throw (QueueException);
    T pop() throw (QueueException);
    void getTop(T& queueFront) const;
private:
    list<T> front;
};

template <class T>
bool GQueue<T>::isEmpty() const{
    //you typed isempty(), changed it to empty(), this is a function in class std::list
	if(front.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
void GQueue<T>::push(const T& newItem) throw(QueueException){
	front.push_back();
    //here, how can you check if push is successfull? if not successful then throw and exception
}

template <class T>
T GQueue<T>::pop()throw (QueueException)
{
	T element;
	if(front.isempty())
	{
		throw new QueueException("Queue is empty.");
	}
	else
	{
		//element = front.pop_front(); you can't do this, pop_front() is void based on
        //std::list doesn't return anything, instead you do this.
        element = front.front();
        //then you pop it
        front.pop_front();
	}
	return element;
    
}
template <class T>
void GQueue<T>::getTop(T& queueFront) const
{
    //you have to check if its empty or not first. coz if its empty then we can't pop
    //anything
    
    if(isEmpty()){
        throw QueueException("Queue is Empty.");
    }else{
        queueFront = front.front();
    }
}