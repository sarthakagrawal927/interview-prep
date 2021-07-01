/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comp(Interval A, Interval B)
{
    return A.start < B.start;
}
vector<Interval> Solution::merge(vector<Interval> &v)
{
    if (v.size() <= 1)
        return v;
    vector<Interval> ans;
    sort(v.begin(), v.end(), comp);
    Interval curr = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (curr.end >= v[i].start)
        {
            curr.end = max(curr.end, v[i].end);
        }
        else
        {
            ans.push_back(curr);
            curr = v[i];
        }
    }
    ans.push_back(curr);
    return ans;
}
