#include <iostream>
using namespace std;

//Key takeaway: Only one pointer can point to the resource. The ownership
// of the resource changes on copy. Only a single handle to the resource
// exists
class ExclusiveCopy
{
private:
    int *_myInt;

public:

    //RAII - Resource Allocation Is Initialization.
    // Resource is allcated when the object is initilized.
    ExclusiveCopy()
    {
        _myInt = (int *) malloc(sizeof(int));
        cout << "resource allocated" << endl;
    }

    // Rule of three. The desctructor, copy constructor and copy assignment methods are implemented

    ~ExclusiveCopy()
    {
        // needed to check for nullptr to avoid double free. Specific to the Exclusive copy policy
        if (_myInt!=nullptr){
            free(_myInt);
            cout << "resource freed" << endl;
        }
    }

    ExclusiveCopy(ExclusiveCopy &source) // note the lvalue ref is not const because we want to change it
    {
        _myInt = source._myInt;
        source._myInt = nullptr;  // make null. This is why the check is made in the desctructor
                                  // Note: the data is not freed, just the ownership is changed
    }

    ExclusiveCopy& operator=(ExclusiveCopy &source)
    {
        if (this==&source){
            return *this;
        }
        _myInt = source._myInt;
        source._myInt = nullptr;
        return *this;
    }

};

int main()
{
    ExclusiveCopy source;
    ExclusiveCopy destination;
    destination = source;

    // problem... why is there only one "resource freed"? Is there a leak?
    return 0;
}