class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        mod = 1000000007
        length = len(nums)
        for i in range(length):
            nums[i] = nums[i] - self.reverse(nums[i])
        nums.sort()
        res = 0
        i = 0
        while i < length - 1:
            count = 1
            while i < length - 1 and nums[i] == nums[i + 1]:
                count += 1
                i += 1
            res = (res % mod + (count * (count - 1)) // 2) % mod
            i += 1

        return int(res % mod)
    def reverse(self, num: int) -> int:
        rev = 0
        while num > 0:
            rev = rev * 10 + num % 10
            num //= 10
        return rev