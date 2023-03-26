class Solution
{
public:
    int prime(int n)
    {
        if (n & 1)
            n -= 2;
        else
            n--;

        int i, j;
        for (i = n; i >= 2; i -= 2)
        {
            if (i % 2 == 0)
                continue;
            for (j = 3; j <= sqrt(i); j += 2)
            {
                if ((i % j == 0))
                    break;
            }
            if ((j > sqrt(i)))
                return i;
        }
        return 2;
    }
    bool primeSubOperation(vector<int> &nums)
    {
        if(nums[0] !=2)
        {
            nums[0] = nums[0] - prime(nums[0]);
        }
        cout<<nums[0]<<" ";
        for(int i =1;i<nums.size();i++)
        {
            if(nums[i] - prime(nums[i]) > nums[i-1])
            {
                nums[i] = nums[i] - prime(nums[i]);
            }else if(nums[i] > nums[i-1])
            {
                int diff = nums[i] - nums[i-1];
                if(diff > 2)
                {
                    nums[i] = nums[i] - prime(diff);
                }
            }else
            {
                return false;
            }
            cout<<nums[i]<<" ";
        }
        return true;
    }
};
