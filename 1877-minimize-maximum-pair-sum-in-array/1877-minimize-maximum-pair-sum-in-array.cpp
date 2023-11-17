class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int minMaxSum = 0;
        for (int i = 0; i < nums.size() / 2; i++) {
            minMaxSum = max(minMaxSum, nums[i] + nums[nums.size() - 1 - i]);
        }
        
        return minMaxSum;
    }
};