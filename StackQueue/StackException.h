#include <iostream>
#include <string>
using namespace std;

class StackException{
public:
    StackException(string message);
    string getError()const;
    ~StackException(){}
    
private:
    string error;
};
