class Solution {
public:
    int majorityElement(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int n=nums.size()-1;
      n=n/2;
      return nums[n];
    }
};
