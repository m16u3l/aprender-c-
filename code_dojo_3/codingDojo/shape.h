#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <utility>

class shape
{
    std::string shape_name;
    int m_x;
    int m_y;
    int m_width;
    int m_height;

public:
    template <typename STRING> 
    shape(STRING && shape_name)
    :shape_name{std::forward<STRING>(shape_name)},
    m_x{0},
    m_y{0},
    m_width{20},
    m_height{20}
    {
    }
    virtual ~shape()
    {
    }
    const std::string& get_name()const
    {
        return shape_name;
    }

    void move(int p_x, int p_y)
    {
        m_x = p_x;  
        m_y = p_y;
    }
};
#endif
