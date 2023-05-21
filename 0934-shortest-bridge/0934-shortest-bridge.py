class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        n = len(grid)
        def neighbors(cell):
            i, j = cell
            if i > 0 and grid[i - 1][j] != -1:
                yield i - 1, j
            if i + 1 < n and grid[i + 1][j] != -1:
                yield i + 1, j
            if j > 0 and grid[i][j - 1] != -1:
                yield i, j - 1
            if j + 1 < n and grid[i][j + 1] != -1:
                yield i, j + 1
                
        def island():
            for i in range(n):
                for j in range(n):
                    if grid[i][j]:
                        grid[i][j] = -1
                        return [(i, j)]

        q, q2, ans = island(), [], 1
        while q:
            q_next = []
            for cell in q:
                for i, j in neighbors(cell):
                    (q_next if grid[i][j] else q2).append((i, j))
                    grid[i][j] = -1
            q = q_next
        while q2:
            q_next = []
            for cell in q2:
                for i, j in neighbors(cell):
                    if grid[i][j] == 1:
                        return ans
                    q_next.append((i, j))
                    grid[i][j] = -1
            ans += 1
            q2 = q_next
        return ans