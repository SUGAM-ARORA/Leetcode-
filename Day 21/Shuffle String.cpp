class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        
    string ans=s;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        int shuffle_pos=indices[i];
        ans[shuffle_pos]=s[i];
    }
    return ans;
    

    }
};
