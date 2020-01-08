class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if prices == []: return 0
        ans, mini = 0, prices[0]
        for i in prices:
            if i - mini > ans:
                ans = i - mini
            mini = min(mini, i)
        return ans