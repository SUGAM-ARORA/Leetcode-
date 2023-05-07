class Solution 
{
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) 
    {
        vector<int> a;
        vector<int> res;
        for (auto x : obstacles)
        {
            int idx = upper_bound(a.begin(), a.end(), x) - a.begin();
            if (idx == a.size())
                a.push_back(x);
            else
                a[idx] = x;
            res.push_back(idx + 1);
        }

        return res;
    }
};