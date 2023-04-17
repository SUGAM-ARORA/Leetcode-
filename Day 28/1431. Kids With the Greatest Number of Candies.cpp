class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi=*max_element(candies.begin(),candies.end()); 
        vector<bool> ans;
        for(int i=0;i<candies.size();i++){
            ans.push_back(candies[i]+extraCandies >= maxi);
        }
        return ans;      
    }
};
