#ifndef LINE_H
#define LINE_H
#include "shape.h"

class line:public shape
{
public:
    line()
    :shape("line")
    {}
    ~line()
    {}
    
};

#endif