#include <iostream>
#include <memory> // this is where smart pointers are called
#include <string>

using namespace std;

class MyClass
{
private:
    string _text;

public:
    MyClass(){}
    MyClass(string text) { _text = text;}
    ~MyClass() {cout << _text << " destroyed" << endl;}
    void setText(string text){_text = text;}
};

int main(int argc, char const *argv[])
{
    //use RAII to create the pointers. allocate the resource during initialization
    // must allocate the resource in the constructor.
    unique_ptr<MyClass> myclass1(new MyClass());            //in the tempaate, it's not MyClass*
    unique_ptr<MyClass> myclass2(new MyClass("String 2"));

    //call memeber functions like normal pointers
    myclass1->setText("String 1");

    // use the dereference like notmal pointers
    *myclass1 = *myclass2;

    // use the .get() to get the raw pointers
    cout << "Objects have stack addresses " << myclass1.get() << " and " << myclass2.get() << endl;

    // not sure where the uniqueness comes to play, so lets copy the pointers (not dereferenced)
    unique_ptr<MyClass> myclass3(new MyClass("String 3"));

    // below is there the compiler disallows copying the pointers around. Error is printed
    //myclass3 = myclass2;



    // no clean up of the pointers needed

    return 0;
}