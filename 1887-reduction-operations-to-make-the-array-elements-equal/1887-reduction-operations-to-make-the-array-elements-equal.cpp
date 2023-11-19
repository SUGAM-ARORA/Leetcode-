#pragma GCC optimize("O3")
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int count=0, sum=0, prev=50001;
        #pragma unroll
        for(int x: nums){
            if (x!=prev)
                count+=sum;
            sum++;
            prev=x;
        }
        return count;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();