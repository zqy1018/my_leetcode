class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        """
        :type n: int
        :rtype: int
        """
        ans = [0] * n
        aans = []
        def solve(n, cur_id, left, straight, right):
            nonlocal ans
            if cur_id == n + 1:
                lst = [("." * ans[i]) + "Q" + ("." * (n - ans[i] - 1)) for i in range(0, n)]
                aans.append(lst)
                return 
            cur = ((left & ((1 << n) - 1)) | straight | right)
            for i in range(0, n):
                j = 1 << i
                if cur & j:
                    continue
                else:
                    ans[cur_id - 1] = i
                    solve(n, cur_id + 1, (left | j) << 1, straight | j, (right | j) >> 1)
        solve(n, 1, 0, 0, 0)
        return ans