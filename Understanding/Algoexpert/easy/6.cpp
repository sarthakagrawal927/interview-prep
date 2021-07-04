// 3 largest numbers

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {1,
                       2,
                       4,
                       232,
                       42,
                       23,
                       4,
                       -3,
                       321},
                top3(3, -1e8);

    for (int i = 0; i < arr.size(); i++)
    {
        if (top3[0] < arr[i])
        {
            if (top3[1] < arr[i])
            {
                if (top3[2] < arr[i])
                {
                    top3[0] = top3[1];
                    top3[1] = top3[2];
                    top3[2] = arr[i];
                }
                else
                {
                    top3[0] = top3[1];
                    top3[1] = arr[i];
                }
            }
            else
                top3[0] = arr[i];
        }
    }
    cout << top3[0] << " " << top3[1] << " " << top3[2];
    return 0;
}