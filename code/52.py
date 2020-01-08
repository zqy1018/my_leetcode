class Solution:
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = 0
        def solve(n, cur_id, left, straight, right):
            nonlocal ans
            if cur_id == n + 1:
                ans += 1
                return 
            cur = ((left & ((1 << n) - 1)) | straight | right)
            for i in range(0, n):
                j = 1 << i
                if cur & j:
                    continue
                else:
                    solve(n, cur_id + 1, (left | j) << 1, straight | j, (right | j) >> 1)
        solve(n, 1, 0, 0, 0)
        return ans