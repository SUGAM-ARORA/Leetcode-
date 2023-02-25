class Solution {
public:
int maxProfit(vector<int>& A) {
        int ans = 0;
        int min_val = A[0];
        for(int i = 1; i < A.size(); i++) {
            min_val = min(min_val, A[i]);
            ans = max(ans, A[i]-min_val);
        }
        return ans;
    }
};
