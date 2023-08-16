from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        result = []
        q = deque()
        i = 0
        
        for j in range(len(nums)):
            while q and q[-1] < nums[j]:
                q.pop()
            q.append(nums[j])
            
            if j - i + 1 == k:
                result.append(q[0])
                if q[0] == nums[i]:
                    q.popleft()
                i += 1
        
        return result