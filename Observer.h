#include <iostream>

using namespace std;

#ifndef Observer_H
#define Observer_H
//interface class
class Observer {
  public:
     virtual void Update(bool buffer_flag) = 0;
};

#endif

