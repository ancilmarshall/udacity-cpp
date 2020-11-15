#include <iostream>

/* The last ownership policy we will be discussing in this course implements a
shared ownership behavior. The idea is to perform a copy or assignment similar
to the default behavior, i.e. copying the handle instead of the content (as with a shallow copy)
while at the same time keeping track of the number of instances that also point
to the same resource. Each time an instance goes out of scope, the counter is
decremented. Once the last object is about to be deleted, it can safely deallocate
the memory resource. We will see later in this course that this is the central idea
 of unique_ptr, which is a representative of the group of smart pointers. */

using namespace std;

