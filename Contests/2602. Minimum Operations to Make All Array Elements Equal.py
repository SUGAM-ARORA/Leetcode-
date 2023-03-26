class Solution:
    def minOperations(self, nums: List[int], queries: List[int]) -> List[int]:
        total = sum(nums)
        nums.sort()
        res = []
        N = len(nums)
        pre = [0]
        for n in nums:
            pre.append(pre[-1] + n)
            
        
        for q in queries:
            cur = 0
            idx = bisect.bisect_left(nums, q)
            
            low = pre[idx]
            potVal = q * (idx)
            cur += abs(potVal - low)
            
            high = pre[-1] - pre[idx]
            potVal = (q * (N - idx))
            cur += abs(potVal - high)
            
            res.append(cur)
        
        return res
