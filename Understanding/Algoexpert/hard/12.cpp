// boggle board
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v1 = {8, 5, 2, 9, 5, 6, 3};

    make_heap(v1.begin(), v1.end());

    printVector(v1);
    heapsort(v1);
    printVector(v1);

    return 0;
}