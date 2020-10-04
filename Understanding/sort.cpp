#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

void bubble(vector<int> array)
{
    int temp;
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = i + 1; j < array.size(); j++)
        {
            if (array[i] > array[j])
            {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}
void selection(vector<int> array)
{
    int temp, m_index;
    for (int i = 0; i < array.size(); i++)
    {
        m_index = i;
        for (int j = i + 1; j < array.size(); j++)
        {
            if (array[m_index] > array[j])
                m_index = j;
        }
        temp = array[i];
        array[i] = array[m_index];
        array[m_index] = temp;
    }
}

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> values(n);

    auto f = []() -> int { return rand() % 10000; };
    generate(values.begin(), values.end(), f);

    while (t--)
    {
        auto start = high_resolution_clock::now();
        sort(values.begin(), values.end());
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken by cpp sort "
             << duration.count() / 1000 << " miliseconds" << endl;

        generate(values.begin(), values.end(), f);
        start = high_resolution_clock::now();
        bubble(values);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken by bubble "
             << duration.count() / 1000 << " miliseconds" << endl;

        generate(values.begin(), values.end(), f);
        start = high_resolution_clock::now();
        selection(values);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken by selection "
             << duration.count() / 1000 << " miliseconds" << endl;

        cout << endl;
    }

    return 0;
}
