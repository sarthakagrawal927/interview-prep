#include <iostream>
using namespace std;

inline int max(int a, int b)
{
    return (a > b) ? a : b;
}
// providing optional arguments (make sure its rightmost)
int sum(int a[], int size, int start = 0)
{
    return 0;
}
int main(int argc, const char **argv)
{
    int *p = new int; // dynamic memory initialization (int heap)
    // stores 4 bytes in heap and 8 bytes in stack for p's address
    *p = 10;
    cout << *p;

    int *ar = new int[100]; // 400 on the heap, 8 bytes on stack
    int n;
    cin >> n;
    int *arr = new int[n]; // allowing memory input in heap

    delete[] arr;

    // the problem with heap memory
    // static memory released automatically by scope of variable
    while (true) // here every iteration i is dropped and a new variable is created, so it has max usage of 4bytes (in stack)
        int i = 10;

    // dynamic memory needs manual memory removal
    while (true) // here after every iteration the pointer (8bytes) are dropped BUT 4 bytes by new int aren't causing your program to crash due to less memory
    {
        int *i = new int;
        // soln
        delete i; // this will delete memory owned by i, i can be reassigned , the 4 bytes get deleted
    }
    int m = 10, n = 6;
    int **a = new int *[m];

    a[1] = new int[n];

    // dont directly delete
    // delete[] a;

    // delete like this for complete clearance
    for (int i = 0; i < m; i++)
    {
        delete[] a[i];
    }
    delete[] a;

    //Why #define is awesome
    // everything defined is pre injected on your code when you compile without taking any extra memory
    // if you want to use  a variable which you use often just define it
    // never use global var, want to share same var pass by reference

    int m = max(5, 6);
    // usual function ends up taking a small hit, like it is called variables are pushed into stack, its separate variables are created
    // not much of a hit, but little performance issue,  which can be prevented by inline function, it just replaces the code of the function
    // wherever it is called and is done by the compiler. which does speeds up
    // why not always use inline ?
    // as the code is written many times in original, it creates a bulky a.out file

    return 0;
}