class Solution {

    int binary_search(vector<int>& nums, int target, int start, int end){
        if(start > end || (start==end && nums[start]!=target)) return -1;
        if(start == end) return start;
        int mid = (start + end)/2;
        if(nums[mid]<nums[start]){
            if(target >= nums[start] || target <= nums[mid]) 
                return binary_search(nums, target, start, mid);
            else 
                return binary_search(nums, target, mid+1, end);
        }else{
            if(target >= nums[start] && target <= nums[mid])
                return binary_search(nums, target, start, mid);
            else
                return binary_search(nums, target, mid+1, end);
        }
    }

public:
    int search(vector<int>& nums, int target) {
        return binary_search(nums, target, 0, nums.size()-1);
    }
};