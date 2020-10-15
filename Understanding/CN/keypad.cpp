#include <math.h>
#include <iostream>
#include <string>
using namespace std;
int getpossibe(int s, string arr[])
{
    if (s == 0)
        return 0;
    int n = s % 10;
    if (n <= 1)
        return getpossibe(s / 10, arr);

    int smallOutput = getpossibe(s / 10, arr);
    if (n == 2)
    {
        for (int i = 0; i < smallOutput; i++)
        {
            arr[smallOutput + i] = arr[i] + 'a';
            arr[smallOutput * 2 + i] = arr[i] + 'b';
            arr[smallOutput * 3 + i] = arr[i] + 'c';
        }
        return smallOutput * 3;
    }
    else if (n == 3)
    {
        for (int i = 0; i < smallOutput; i++)
        {
            arr[smallOutput + i] = arr[i] + 'd';
            arr[smallOutput * 2 + i] = arr[i] + 'e';
            arr[smallOutput * 3 + i] = arr[i] + 'f';
        }
        return smallOutput * 3;
    }
    else if (n == 4)
    {
        for (int i = 0; i < smallOutput; i++)
        {
            arr[smallOutput + i] = arr[i] + 'g';
            arr[smallOutput * 2 + i] = arr[i] + 'h';
            arr[smallOutput * 3 + i] = arr[i] + 'i';
        }
        return smallOutput * 3;
    }
    else if (n == 5)
    {
        for (int i = 0; i < smallOutput; i++)
        {
            arr[smallOutput + i] = arr[i] + 'j';
            arr[smallOutput * 2 + i] = arr[i] + 'k';
            arr[smallOutput * 3 + i] = arr[i] + 'l';
        }
        return smallOutput * 3;
    }
    else if (n == 6)
    {
        for (int i = 0; i < smallOutput; i++)
        {
            arr[smallOutput + i] = arr[i] + 'm';
            arr[smallOutput * 2 + i] = arr[i] + 'n';
            arr[smallOutput * 3 + i] = arr[i] + 'o';
        }
        return smallOutput * 3;
    }
    else if (n == 7)
    {
        for (int i = 0; i < smallOutput; i++)
        {
            arr[smallOutput + i] = arr[i] + 'p';
            arr[smallOutput * 2 + i] = arr[i] + 'q';
            arr[smallOutput * 3 + i] = arr[i] + 'r';
            arr[smallOutput * 4 + i] = arr[i] + 's';
        }
        return smallOutput * 4;
    }
    else if (n == 8)
    {
        for (int i = 0; i < smallOutput; i++)
        {
            arr[smallOutput + i] = arr[i] + 't';
            arr[smallOutput * 2 + i] = arr[i] + 'u';
            arr[smallOutput * 3 + i] = arr[i] + 'v';
        }
        return smallOutput * 3;
    }
    else if (n == 9)
    {
        for (int i = 0; i < smallOutput; i++)
        {
            arr[smallOutput + i] = arr[i] + 'w';
            arr[smallOutput * 2 + i] = arr[i] + 'x';
            arr[smallOutput * 3 + i] = arr[i] + 'y';
            arr[smallOutput * 4 + i] = arr[i] + 'z';
        }
        return smallOutput * 4;
    }
}

void getpos(int n, string a)
{
    if (n == 0)
    {
        cout << a << endl;
        return;
    }
    int s = n % 10;
    if (s <= 1)
        getpos(n / 10, a);
    else if (s == 2)
    {
        getpos(n / 10, a + "a");
        getpos(n / 10, a + "b");
        getpos(n / 10, a + "c");
    }
    else if (s == 3)
    {
        getpos(n / 10, a + "d");
        getpos(n / 10, a + "e");
        getpos(n / 10, a + "f");
    }
    else if (s == 4)
    {
        getpos(n / 10, a + "g");
        getpos(n / 10, a + "h");
        getpos(n / 10, a + "i");
    }
    else if (s == 5)
    {
        getpos(n / 10, a + "j");
        getpos(n / 10, a + "k");
        getpos(n / 10, a + "l");
    }
    else if (s == 6)
    {
        getpos(n / 10, a + "m");
        getpos(n / 10, a + "n");
        getpos(n / 10, a + "o");
    }
    else if (s == 7)
    {
        getpos(n / 10, a + "p");
        getpos(n / 10, a + "q");
        getpos(n / 10, a + "r");
        getpos(n / 10, a + "s");
    }
    else if (s == 8)
    {
        getpos(n / 10, a + "t");
        getpos(n / 10, a + "u");
        getpos(n / 10, a + "v");
    }
    else if (s == 9)
    {
        getpos(n / 10, a + "w");
        getpos(n / 10, a + "x");
        getpos(n / 10, a + "y");
        getpos(n / 10, a + "z");
    }
}
int main(int argc, const char **argv)
{
    int number;
    cin >> number;
    // string *arr = new string[1000];
    // int n = getpossibe(number, arr); // not working

    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << endl;

    getpos(number, "");
    return 0;
}