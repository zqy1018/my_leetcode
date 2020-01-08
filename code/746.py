class Solution:
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        len1 = len(cost)
        ans = [3000000000] * len1
        ans[0], ans[1] = cost[0], cost[1]
        for i in range(2, len1):
            ans[i] = min(ans[i - 2], ans[i - 1]) + cost[i]
        return min(ans[-1], ans[-2])