class Solution {
private:
    vector<vector<int>> dp;
    int helper(int idx,int remainingWalls,vector<int> &cost,vector<int> &time) {
        //base cases
        if(remainingWalls <= 0) return 0;
        if(idx < 0) return 1e9;
        if(dp[idx][remainingWalls] != -1) return dp[idx][remainingWalls]; 

        int take = cost[idx]+helper(idx-1,remainingWalls-1-time[idx],cost,time);
        int notTake = helper(idx-1,remainingWalls,cost,time);

        return dp[idx][remainingWalls] = min(take,notTake);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        dp.resize(n,vector<int>(n+1,-1));
        return helper(n-1,n,cost,time);
    }
};