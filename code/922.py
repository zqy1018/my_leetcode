class Solution:
    def sortArrayByParityII(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        ans = [0] * len(A)
        cnt1, cnt2 = 0, 1
        for i in A:
            if i & 1:
                ans[cnt2] = i
                cnt2 += 2
            else:
                ans[cnt1] = i
                cnt1 += 2
        return ans

