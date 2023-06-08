class Solution(object):
    def countNegatives(self, grid):
        i = 0
        j = len(grid[0]) - 1
        count = 0
        
        while i < len(grid) and j >= 0:
            if grid[i][j] < 0:
                count += (len(grid) - i)
                j -= 1
            elif grid[i][j] >= 0:
                i += 1
        
        return count
        