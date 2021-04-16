//https://www.geeksforgeeks.org/maximize-product-of-subarray-sum-with-its-minimum-element/
#include <bits/stdc++.h>
using namespace std;

void maxValue(int a[], int n)
{
    int presum[n];

    presum[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        presum[i] = presum[i - 1] + a[i];
    }

    int l[n], r[n];

    stack<int> st;

    for (int i = 1; i < n; i++)
    {
        while (!st.empty() &&
               a[st.top()] >= a[i])
            st.pop();
        if (!st.empty())
            l[i] = st.top() + 1;
        else
            l[i] = 0;
        st.push(i);
    }

    while (!st.empty())
        st.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() &&
               a[st.top()] >= a[i])
            st.pop();

        if (!st.empty())
            r[i] = st.top() - 1;
        else
            r[i] = n - 1;
        st.push(i);
    }

    int maxProduct = 0;

    int tempProduct;

    for (int i = 0; i < n; i++)
    {

        tempProduct = a[i] * (presum[r[i]] -
                              (l[i] == 0 ? 0 : presum[l[i] - 1]));
        maxProduct = max(maxProduct,
                         tempProduct);
    }
    cout << maxProduct;
}

int main()
{
    int n = 6;
    int arr[] = {3, 1, 6, 4, 5, 2};

    maxValue(arr, n);
}
