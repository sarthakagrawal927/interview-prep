// Heap Construction
#include <iostream>
#include <vector>
using namespace std;

class Heap
{
private:
    vector<int> arr;
    int size;
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void siftUp(int currIdx)
    {
        int parentcurrIdx = (currIdx - 1) / 2;
        while (currIdx > 0 && arr[currIdx] < arr[parentcurrIdx])
        {
            swap(arr[parentcurrIdx], arr[currIdx]);
            currIdx = parentcurrIdx;
            parentcurrIdx = (currIdx - 1) / 2;
        }
    }

    void siftDown(int currIdx)
    {
        int child1 = currIdx * 2 + 1, indexToSwap;
        while (child1 < size - 1)
        {
            int child2 = (currIdx * 2 + 2) < size ? currIdx * 2 + 2 : -1;
            if (child2 != -1 && arr[child2] < arr[child1])
                indexToSwap = child2;
            else
                indexToSwap = child1;

            if (arr[indexToSwap] < arr[currIdx])
            {
                swap(arr[indexToSwap], arr[currIdx]);
                currIdx = indexToSwap;
                child1 = currIdx * 2 + 1;
            }
            else
                return;
        }
    }

    bool isEmpty()
    {
        return size == 0;
    }

public:
    void build(vector<int> a) // sift down faster, we will apply sift down on every item from bottom
    {
        arr = a;
        size = arr.size();
        int firstParentIdx = (size - 2) / 2;
        for (int i = firstParentIdx; i >= 0; i--)
        {
            siftDown(i);
        }
    }

    void insert(int a)
    {
        arr.push_back(a);
        siftUp(size);
        size++;
    }

    void remove()
    {
        swap(arr[0], arr[size - 1]);
        arr.pop_back();
        size--;
        siftDown(0);
    }

    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    int peek()
    {
        return arr[0];
    }
};

int main()
{
    Heap h;
    vector<int> arr = {12, 15, 9, 7, 8, 14};
    h.build(arr);
    h.print();
    h.insert(13);
    h.insert(19);
    h.remove();
    h.print();

    return 0;
}
