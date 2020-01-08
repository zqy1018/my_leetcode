class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        ans = [1]
        for i in range(0, rowIndex):
            ans.append(ans[-1] * (rowIndex - i) / (i + 1))
        return ans