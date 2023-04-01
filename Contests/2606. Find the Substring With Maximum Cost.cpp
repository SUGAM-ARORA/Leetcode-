class Solution {
public:
int maxSubArraySum(vector<int>&a, int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
     for (int i = 0; i < size; i++) 
     {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
        {       max_so_far = max_ending_here;}
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
    int maximumCostSubstring(string s, string ch, vector<int>& vs) {
        map<char,int>m;
        char c = 'a';
        m[c] = 1;
        for(int  i =1;i<26;i++){
            c++;
            m[c] = i+1;
        }
        int n1 = ch.size();
        for(int i =0;i<n1;i++){
            m[ch[i]] = vs[i];
        }
        vector<int>v;
        for(int i =0;i<s.length();i++){
            v.push_back(m[s[i]]);
        }
        int ans = maxSubArraySum(v,v.size());
        if(ans<0){
            return 0;
        }else{
            return ans;
        }
    }
};
