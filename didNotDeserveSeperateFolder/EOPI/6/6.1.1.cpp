//Dutch flag - n color
//Algorithm: Will do each color one by one, Complexity O(cn) c-> number of component, n-> number of element
#include <iostream>

using namespace std;
#define rep(i, start, end) for (int i = start; i < end; i++)

int main()
{
    int element[20] = {4, 2, 3, 5, 4, 1, 3, 4, 4, 2, 2, 3, 1, 4, 4, 2, 5, 1, 1, 5}; // number of element
    int component[5] = {0};                                                         // number of component
    int start_index;

    //j is the current component
    rep(j, 0, 4) // 0 to number_Of_components - 1, as last component will automatically be sorted
    {
        start_index = (j == 0) ? 0 : component[j - 1] - 1; // 0 for start, else starting point of prev. color's last element, as sorted b4 that
        // i is the element of the above component
        rep(i, start_index, 20)
        {
            if (element[i] == j + 1) // element found of current component
            {
                element[i] = element[component[j]];
                element[component[j]] = j + 1; //Equivalent of swapping, we just dont have to store j+1
                component[j]++;                // increasing position of last occurrence of element
            }
        }
        component[j + 1] = component[j]; //updating the position for starting for next iteration
        rep(i, 0, 20) cout << element[i] << " ";
        cout << endl;
    }

    rep(i, 0, 20) cout << element[i] << " ";
}