#include <vector>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> A;
    // to illustrate how A.reserve(X) removes the dynamic increase of vector
    A.reserve(400);
    // v.at(x) is safer to access in comparison to v[x], dont use either for insertiond
    for (int i = 0; i < 500; i++)
    {
        A.push_back(i + 1);
        cout << A.size() << " " << A.capacity() << endl;
    }
    return 0;
}
