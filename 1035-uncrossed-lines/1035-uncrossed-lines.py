class Solution:
    def maxUncrossedLines(self, nums1: List[int], nums2: List[int]) -> int:
        @lru_cache(None)
        def dp(i,j):
            if i>=len(nums1) or j>=len(nums2):
                return 0
            maxi=0
            if nums1[i]==nums2[j]:
                maxi=1+dp(i+1,j+1)
            maxi=max(maxi,dp(i+1,j),dp(i,j+1))
            return maxi
        return dp(0,0)
        