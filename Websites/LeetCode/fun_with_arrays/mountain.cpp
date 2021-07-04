class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        int i = 0, start = 0, dir = 0;
        if (arr.size() < 2)
            return 0;
        for (i = 0; i < arr.size() - 1; i++)
        {
            if (!start)
            {
                if (arr[i] >= arr[i + 1])
                    return 0;
                start = 1;
            }
            if (arr[i] > arr[i + 1])
            {
                dir = 1;
                break;
            }
            if (arr[i] == arr[i + 1])
                return 0;
        }
        for (; i < arr.size() - 1; i++)
        {
            if (arr[i] <= arr[i + 1])
                return 0;
        }
        return 1 && dir;
    }
};