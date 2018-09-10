#ifndef PHOTOSHOP_H
#define PHOTOSHOP_H
#include <memory>
#include <vector>
#include <string>
#include "shape.h"

using namespace std;
template <class T>
class photoshop
{
private:
    vector<unique_ptr <shape>> shapes;
public:
    using iterator = vector<unique_ptr <shape>>::iterator;
    template <typename TYPESHAPE>
    void add_shape(TYPESHAPE&& new_shape)
    {
        shapes.push_back(forward<TYPESHAPE>(new_shape));
    }
    // Move_shape
    // Resize_shape
    void delete_shape()
    {

    }

    iterator begin()
    {
        return shapes.begin();
    }

    iterator end()
    {
        return shapes.end();
    }

    shape& operator[](int index)
    {
        return *shapes[index];
    }
    // show_image()
    // quit
};
#endif