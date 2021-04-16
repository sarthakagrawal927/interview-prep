#include <iostream> //#HEAP - Complete Binary Tree
#include "pq.h"
using namespace std;

int main()
{
    PQ p;
    p.insert(4);
    p.insert(234);
    p.insert(23);
    p.insert(53);
    p.insert(23);
    p.insert(12);
    p.insert(423);

    cout << p.getSize() << endl;
    cout << p.getMin() << endl;

    while (!p.isEmpty()) // inserting and popping = heap sort
    {
        cout << p.remove() << endl;
    }
    return 0;
}