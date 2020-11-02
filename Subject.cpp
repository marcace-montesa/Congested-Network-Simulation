#include <iostream>
#include "Observer.cpp"
using namespace std;
//interface class
class Subject 
{
    public:
    
     virtual void register_observer(Observer *o) = 0;
     virtual void remove_observer(Observer *o) = 0;
     virtual void notify_observer(bool buffer_flag);
};
