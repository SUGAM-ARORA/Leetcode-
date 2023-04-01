class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) 
    {
        long long n=arr.size();
        if(__gcd(n,(long long)k)==1)
        {
            return minCost(arr,n);
        }
        else{
            long long ans=0;
            for(int i=0;i<__gcd(n,(long long)k);i++)
            {
                vector<int>v1;
                for(int j=i;j<arr.size();j+=__gcd(n,(long long)k))
                    v1.push_back(arr[j]);
                ans+=minCost(v1,v1.size());
            }
            return ans;
        }
        return 0;
    }
    long long minCost(vector<int>&A, int x)
    {
        long long cost = 0;
        sort(A.begin(), A.end());
        long long K = A[x / 2];
        for (int i = 0; i < x; ++i)
            cost += abs(A[i] - K);
        if (x % 2 == 0) {
            long long tempCost = 0;
            K = A[(x / 2) - 1];
            for (int i = 0; i < x; ++i)
                tempCost += abs(A[i] - K);
            cost = min(cost, tempCost);
        }
        return cost;
    }
};
