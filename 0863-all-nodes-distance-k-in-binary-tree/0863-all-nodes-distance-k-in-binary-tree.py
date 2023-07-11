# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque

class Solution:
    def getParentsByBFS(self, parent, root):
        queue = deque()
        queue.append(root)
        while queue:
            n = len(queue)
            while n > 0:
                curr = queue.popleft()
                if curr.left:
                    parent[curr.left] = curr
                    queue.append(curr.left)
                if curr.right:
                    parent[curr.right] = curr
                    queue.append(curr.right)
                n -= 1
    
    def getParentsByDFS(self, parent, root):
        if not root:
            return
        if root.left:
            parent[root.left] = root
        if root.right:
            parent[root.right] = root
        self.getParentsByDFS(parent, root.left)
        self.getParentsByDFS(parent, root.right)
    
    def distanceK(self, root, target, k):
        parent = {}
        self.getParentsByDFS(parent, root)
        queue = deque()
        visited = {target: True}
        queue.append(target)
        level = 0
        while queue:
            n = len(queue)
            if level == k:
                break
            level += 1
            while n > 0:
                curr = queue.popleft()
                if curr.left and curr.left not in visited:
                    visited[curr.left] = True
                    queue.append(curr.left)
                if curr.right and curr.right not in visited:
                    visited[curr.right] = True
                    queue.append(curr.right)
                if curr in parent and parent[curr] not in visited:
                    visited[parent[curr]] = True
                    queue.append(parent[curr])
                n -= 1
        ans = []
        while queue:
            ans.append(queue.popleft().val)
        return ans