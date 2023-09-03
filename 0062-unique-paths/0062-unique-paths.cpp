class Solution {
private:
    // Private helper function for calculating unique paths recursively with memoization
    int solve(int i, int j, int m, int n, vector<vector<int>> &dp) 
    {
        // Base case: If we are out of bounds, return 0 (no valid path)
        if (i >= m || j >= n) 
        {
            return 0;
        }
        
        // Base case: If we've reached the bottom-right corner, return 1 (one valid path)
        if (i == m - 1 && j == n - 1) 
        {
            return 1;
        }
        
        // If the result for the current position (i, j) has already been calculated, return it
        if (dp[i][j] != -1) 
        {
            return dp[i][j];
        }
        
        // Calculate the number of unique paths by moving right and down recursively
        dp[i][j] = solve(i + 1, j, m, n, dp) + solve(i, j + 1, m, n, dp);
        
        // Return the calculated result for this position
        return dp[i][j];
    }

public:
    // Public function to calculate unique paths in an m x n grid
    int uniquePaths(int m, int n) 
    {
        // Create a memoization table (dp) with dimensions (m+1) x (n+1)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        
        // Call the solve function with initial position (0, 0) and the memoization table
        return solve(0, 0, m, n, dp);
    }
};