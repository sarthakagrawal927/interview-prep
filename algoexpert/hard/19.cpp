// Min Max stack

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Stack
{
    int size = -1;
    vector<int> st;
    vector<pair<int, int>> minmax;

public:
    int getmin() { return minmax[size].first; }
    int getmax() { return minmax[size].second; }
    int getpeek() { return st[size]; }
    int getsize() { return size + 1; }
    bool isEmpty() { return size == -1; }
    void push(int n)
    {
        if (size == -1)
        {
            minmax.push_back(make_pair(n, n));
        }
        else
        {
            int mi = min(n, minmax[size].first);
            int ma = max(n, minmax[size].second);
            minmax.push_back(make_pair(mi, ma));
        }

        st.push_back(n);
        size++;
    }
    void pop()
    {
        if (size == -1)
        {
            cout << "empty";
            return;
        }
        size--;
        minmax.pop_back();
        st.pop_back();
    }
};

int main()
{
    Stack s;
    s.push(2);
    s.push(3);
    s.push(5);
    s.push(4);
    s.push(3);

    cout << s.getpeek();
    cout << s.getmax();
    cout << s.getmin();

    s.pop();

    s.push(7);
    s.pop();

    cout << s.getpeek();
    cout << s.getmax();
    cout << s.getmin();

    return 0;
}
