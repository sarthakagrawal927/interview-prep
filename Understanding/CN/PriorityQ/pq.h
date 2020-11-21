#include <iostream> //#HEAP - Complete Binary Tree + root > L & r
#include <vector>
#include <algorithm>
using namespace std;

class PQ
{
    vector<int> pq;

public:
    PQ()
    {
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
            return 0;
        return pq[0];
    }

    void insert(int val)
    {
        pq.push_back(val);

        //up -heapify

        int childIndex = pq.size() - 1;

        while (childIndex > 0) //child not at root
        {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
                break; //It has reached its correct position
            childIndex = parentIndex;
        }
    }

    int remove()
    {
        if (isEmpty())
            return -1;
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        //down-heapify

        int parentIndex = 0;

        int leftCI = 2 * parentIndex + 1;
        int rightCI = 2 * parentIndex + 2;
        while (leftCI < pq.size())
        {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[leftCI])
                minIndex = leftCI;

            if (rightCI < pq.size() && pq[minIndex] > pq[rightCI])
                minIndex = rightCI;

            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftCI = 2 * parentIndex + 1;
            rightCI = 2 * parentIndex + 2;
        }

        return ans;
    }
};