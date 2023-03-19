class Solution:
    def findScore(self, nums: List[int]) -> int:
        x = len(nums)
        mkd = [False] * x
        nums_with_idx = [(nums[i], i) for i in range(x)]
        nums_with_idx.sort()
        score = 0
        for num, idx in nums_with_idx:
            if not mkd[idx]:
                score += num
                mkd[idx] = True
                if idx > 0:
                     mkd[idx-1] = True
                if idx < x-1:
                    mkd[idx+1] = True
        return score
