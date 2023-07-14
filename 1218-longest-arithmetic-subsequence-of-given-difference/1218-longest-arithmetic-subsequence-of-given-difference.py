class Solution:
    def longestSubsequence(self, arr: List[int], d: int) -> int:
        mp=defaultdict(int)
        mx=0
        for i in arr:
            mp[i]=mp[i-d]+1
            mx=max(mp[i],mx)
        return mx
        