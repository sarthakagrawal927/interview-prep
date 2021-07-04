// continuous median
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<double> ans)
{
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> v = {5, 10, 100, 200, 6, 13, 14};
    vector<double> medianArray;
    priority_queue<int> maxHeap;                            //lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; //upper half
    for (int i = 0; i < v.size(); i++)
    {
        // inserting in heap
        if (maxHeap.empty() || maxHeap.top() > v[i])
            maxHeap.push(v[i]);
        else
            minHeap.push(v[i]);

        // making sure about balance
        if ((maxHeap.size() - minHeap.size()) == 2)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if ((minHeap.size() - maxHeap.size()) == 2)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        cout << maxHeap.size() << " " << minHeap.size() << endl;
        // inserting
        double median = 0.0;
        if (maxHeap.size() > minHeap.size())
        {
            median = maxHeap.top() * 1.0;
        }
        else if (minHeap.size() > maxHeap.size())
        {
            median = minHeap.top() * 1.0;
        }
        else
            median = (minHeap.top() + maxHeap.top()) / 2.0;
        medianArray.push_back(median);
    }
    printVector(medianArray);
    return 0;
}