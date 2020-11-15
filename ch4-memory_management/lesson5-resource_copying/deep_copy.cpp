#include <iostream>
using namespace std;


class DeepCopy
{
private:
    int *_myInt;

public:

    //constructor with one parameter
    DeepCopy(int val)
    {
        _myInt = (int*) malloc(sizeof(int));
        *_myInt = val;
        cout << "C'tor: resource allocated at address " << _myInt << endl;
    }

    // destructor
    ~DeepCopy()
    {
        free(_myInt);
        cout << "D'tor: resource freed at address " << _myInt << endl;
    }

    // copy constructor
    DeepCopy(const DeepCopy &source)
    {
        _myInt = (int*) malloc(sizeof(int));
        *_myInt = *source._myInt;
        cout << "Copy C'tor: resource allocated at address " << _myInt << " with data " << *_myInt << endl;
    }

    // copy assignment operator
    DeepCopy& operator=(const DeepCopy &source)
    {
        *_myInt = *source._myInt;
        cout << "Assignment: resource allocated at address " << _myInt << " with data " << *_myInt << endl;
        return *this;
    }
};


int main()
{
    DeepCopy source(42);
    DeepCopy dest1(source);  // copy constructor
    DeepCopy dest2 = dest1;  // copy constructor

    return 0;
}