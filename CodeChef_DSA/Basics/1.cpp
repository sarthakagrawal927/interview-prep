//Check Permutation: Given two strings, write a method to decide if one is a permutation of the other
#include <iostream>

using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)

int main()
{
    int vect[100000];
    int i = 0;
    vect[i] = 0;
    while (vect[i] != 42)
    {
        cin >> vect[i];
        if (vect[i] == 42)
            return 0;
        cout << vect[i] << endl;
        i++;
    }
}