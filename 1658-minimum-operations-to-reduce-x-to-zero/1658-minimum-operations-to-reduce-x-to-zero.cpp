class Solution {
public:
    int minOperations(std::vector<int>& nums, int x) {
        int total = std::accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;
        int left = 0;
        int n = nums.size();
        int maxLength = -1;
        int runningSum = 0;

        for (int right = 0; right < n; right++) {
            runningSum += nums[right];

            while (runningSum > target && left <= right) {
                runningSum -= nums[left];
                left++;
            }

            if (runningSum == target) {
                maxLength = std::max(maxLength, right - left + 1);
            }
        }

        return maxLength != -1 ? n - maxLength : -1;
    }
};