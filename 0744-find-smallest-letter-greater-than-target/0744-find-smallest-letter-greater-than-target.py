class Solution:
    def nextGreatestLetter(self, letters, target):
        left = 0
        right = len(letters) - 1
        while left <= right:
            mid = (left + right) // 2
            if letters[mid] <= target:
                left = mid + 1
            else:
                right = mid - 1

        return letters[0] if left == len(letters) else letters[left]
        