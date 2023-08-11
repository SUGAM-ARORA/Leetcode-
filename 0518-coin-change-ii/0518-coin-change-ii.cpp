class Solution {
public:
int dp[5001][301];
int solve(int amount,vector<int>&coins,int i){
    if(amount==0){
        return 1;
    }
    if(dp[amount][i]!=-1)
    return dp[amount][i];

    if(i==coins.size())
    return 0;
    
    int tk=0;
    if(coins[i]<=amount){
        tk=solve(amount-coins[i],coins,i);
    }
    int nt=solve(amount,coins,i+1);
    return dp[amount][i]=tk+nt;
}
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
         return solve(amount,coins,0);
    }
};