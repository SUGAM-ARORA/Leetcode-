# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.prev = float('inf')
        self.ans = float('inf')
    
    def getMinimumDifference(self, root):
        self.inOrder(root)
        return self.ans
    
    def inOrder(self, root):
        if root.left:
            self.inOrder(root.left)
        
        self.ans = min(self.ans, abs(root.val - self.prev))
        self.prev = root.val
        
        if root.right:
            self.inOrder(root.right)
        
        