class Solution { 
public: 
    int maximizeGreatness(vector<int>& nums) { 
     sort(nums.begin(),nums.end()); 
        int i=0; 
        int j=1; 
        int k=nums.size(); 
        int count=0; 
        while(j<k){ 
            if(nums[i]<nums[j]) 
            { 
                i++; 
                j++; 
                count++; 
            } 
            else{ 
                j++; 
            } 
        } 
        return count; 
    } 
};
