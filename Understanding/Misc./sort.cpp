#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;
#define print(v)                               \
    for (auto i = v.begin(); i < v.end(); i++) \
        cout << *i << " ";

void countSortRadix(vector<int> &array, int exp)
{
    int count[10] = {0}, output[10000], i;

    int n = array.size();
    for (i = 0; i < n; i++) // counting freq of each
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++) //prefix array
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }
    for (i = 0; i < 10000; i++)
        array[i] = output[i];
}

// COunt Sort algo 5 times faster than builtin sort till length of array = 1e5, then it slows down due to huge memory allocation
void countSort(vector<int> &array)
{
    int count[10000] = {0}, output[10000], i;

    int n = array.size();
    for (i = 0; i < n; i++) // counting freq of each
        count[array[i]]++;

    for (i = 1; i < 10000; i++) //prefix array
        count[i] += count[i - 1];

    for (i = 0; i < n; i++)
    {
        output[count[array[i]] - 1] = array[i];
        --count[array[i]];
    }
    for (i = 0; i < 10000; i++)
        array[i] = output[i];
}

void radixSort(vector<int> array)
{
    int m = *max(array.begin(), array.end());
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countSortRadix(array, exp);
    }
    print(array);
}

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
    int n = 10000, t = 1;
    cin >> t;
    vector<int> values(n);

    auto f = []() -> int
    { return rand() % 10000; };
    generate(values.begin(), values.end(), f);

    while (t--)
    {
        auto start = high_resolution_clock::now();
        // Introsort is used by CPP. Its a mix of heap sort, quick sort and insertion sort
        sort(values.begin(), values.end());
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "cpp sort "
             << duration.count() << " microseconds" << endl;

        // generate(values.begin(), values.end(), f);
        // start = high_resolution_clock::now();
        // bubble(values);
        // stop = high_resolution_clock::now();
        // duration = duration_cast<microseconds>(stop - start);
        // cout << "bubble "
        //      << duration.count() << " microseconds" << endl;

        // generate(values.begin(), values.end(), f);
        // start = high_resolution_clock::now();
        // selection(values);
        // stop = high_resolution_clock::now();
        // duration = duration_cast<microseconds>(stop - start);
        // cout << "selection "
        //      << duration.count() << " microseconds" << endl;

        // generate(values.begin(), values.end(), f);
        // start = high_resolution_clock::now();
        // countSort(values);
        // stop = high_resolution_clock::now();
        // duration = duration_cast<microseconds>(stop - start);
        // cout << "count sort "
        //      << duration.count() << " microseconds" << endl;

        generate(values.begin(), values.end(), f);
        start = high_resolution_clock::now();
        radixSort(values);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "radix sort "
             << duration.count() << " microseconds" << endl;

        cout << endl;
    }

    return 0;
}
