class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        unordered_set<float> s;
        for (int i = 0; i < arr.size(); i++)
        {
            float temp = arr[i] * 2.0, temp2 = arr[i] / 2.0;
            if (s.find(temp) != s.end() || s.find(temp2) != s.end())
                return 1;
            s.insert((float)arr[i]);
        }
        return 0;
    }
};