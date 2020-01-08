class Solution:
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        ans1, ans2 = [], []
        for i in A:
            if i & 1:
                ans1.append(i)
            else:
                ans2.append(i)
        return ans2 + ans1