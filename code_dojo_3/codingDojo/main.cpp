#include <iostream>
#include "line.h"
#include "rectangle.h"
#include "circle.h"
#include "photoshop.h"
#include "text_renderer.h"
#include <memory>
#include <string>

using namespace std;

void draw_menu()
{
    cout << "MENU:\n";
    cout << "  1. Add shape\n";
    cout << "  2. Move shape\n";
    cout << "  3. Resize shape\n";
    cout << "  4. Delete shape\n";
    cout << "  5. Quit\n";
}
int menu_option_add()
{
    int op;
    cout << "Shape:\n";
    cout << "  1. Circle\n";
    cout << "  2. Line\n";
    cout << "  3. Rectangle\n";
    cout << "  4. Quit\n";
    cin >>op;
    return op;
}

template <typename T>
shape &list_shapes(photoshop<T> &ps)
{
    cout << "Choose a shape to use :\n";
    size_t index = 0;
    for (auto &it:ps)
    {
        cout <<++index<<": "<< it->get_name()<<"\n";
    }
    cout << "shape index: ";
    cin >> index;
    return ps[index-1];
}

template <typename T>
void process_move(photoshop<T> &ps)
{
    int x;
    int y;
    auto& sp = list_shapes(ps);
    cout << "enter new axis: ";
    cin>>x;
    cin>>y;
    sp.move(x, y);
}

template <typename T>
void process_resize(photoshop<T> &ps)
{
    
}

template <typename T>
void process_delete(photoshop<T> &ps)
{
    
}

template <typename T>
void process_add(T &ps)
{
    int Option = menu_option_add();
    switch(Option)
    {
        case 1: ps.add_shape(make_unique<circle>());
                break;
        case 2: ps.add_shape(make_unique<line>());
                break;
        case 3: ps.add_shape(make_unique<rectangle>());
                break;
        case 4: break;
        default: throw -1;
    }

}
template <typename T>
void process_option(int op, photoshop<T> &ps)
{
    switch(op)
    {
        case 1: process_add(ps);
                break;
        case 2: process_move(ps);
                break;
        case 3: process_resize(ps);
                break;
        case 4: process_delete(ps);
                break;
        case 5: break;
        default: throw -1;
    }

}

int main()
{
    photoshop<text_renderer> ps;

    int op = -1;
    while (op != 5)
    {
        // ps.show_image();
        draw_menu();
        cin >> op;
        process_option(op, ps);
    }
}
