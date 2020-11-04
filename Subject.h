#include <iostream>
#include "Observer.h"
using namespace std;

#ifndef Subject_H
#define Subject_H
//interface class
class Subject 
{
    public:
    
     virtual void register_observer(Observer *o) = 0;
     virtual void remove_observer(Observer *o) = 0;
     virtual void notify_observer(bool buffer_flag) = 0;
};

#endif
