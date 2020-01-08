class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        len1, len2 = len(obstacleGrid), len(obstacleGrid[0])
        if obstacleGrid[0][0] or obstacleGrid[len1 - 1][len2 - 1]:
            return 0
        ans = [[0] * len2 for i in range(0, len1)]
        ans[0][0] = 1
        for i in range(0, len1):
            if i != 0 and not obstacleGrid[i][0]:
                ans[i][0] += ans[i - 1][0]
            for j in range(1, len2):
                if not obstacleGrid[i][j]:
                    ans[i][j] += ans[i][j - 1]
                    if i: ans[i][j] += ans[i - 1][j]
        return ans[len1 - 1][len2 - 1]