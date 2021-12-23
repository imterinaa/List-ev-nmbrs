#include <iostream>
#include "List.h"
int main() {
    MyList<int> t;
    for (int i = 0; i < 10; i++)
    {
        t.Push(10*i);
    }
    t.PrintList();
    t.Delete2k();
    std::cout << "С четными номерами:\n";
    t.PrintList();
        return 0;


    }

