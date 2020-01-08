class Solution:
    def shortestSubarray(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        dict1, sum, ans = {}, 0, len(A) + 1
        dict1[0] = 0
        for idx, i in enumerate(A):
            sum += i
            res = dict1.get(sum - K, -1)
            if res != -1:
                ans = min(ans, idx - res)
            dict1[sum] = idx
        
