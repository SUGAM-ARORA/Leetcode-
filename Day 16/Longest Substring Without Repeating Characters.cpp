class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, i = 0, j = 0,n= s.length();
        vector<int> v(256,0);
        while(i<n){
            v[s[i]]++;
            while(v[s[i]]>1){
                v[s[j]]--;
                j++;
            }
            ans = max(i-j+1,ans);
            i++;
        }
        return ans;
    }
};
