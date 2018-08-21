#include "mmap.h"
#include <string>
#include <iostream>

auto main() -> int
{
    try
    {
        mmap<int, string> m1;
        m1.insert(20, "veinte");
        m1.insert(10, "diez");
        m1.insert(40, "cuarenta");
        m1.insert(0, "zero");
        m1.insert(30, "cuarenta");
        m1.insert(60, "cuarenta");
        m1.insert(50, "cuarenta");
    }

    m1.iterate()
    {

    }

    cout << "Count: " << endl;
    
    cout






    catch(const key_not_found& e)
    {
        cout << "Key not found" << endl;
    }

    return 0;
}