class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=0){
                swap(nums[j],nums[s]);
                s++;
            }
        }
    }
};