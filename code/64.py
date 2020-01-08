class Solution:
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        len1, len2 = len(grid), len(grid[0])
        ans = [[0] * len2 for i in range(0, len1)]
        ans[0][0] = grid[0][0]
        for i in range(0, len1):
            for j in range(0, len2):
                if i or j: 
                    t = 3000000000
                    if i: t = min(t, ans[i - 1][j])
                    if j: t = min(t, ans[i][j - 1])
                    ans[i][j] = grid[i][j] + t
        return ans[len1 - 1][len2 - 1]