class Solution:
    def numMovesStonesII(self, stones: List[int]) -> List[int]:
        stones.sort()
        n = len(stones)
        maxi = max(stones[n - 1] - stones[1] + 1, stones[n - 2] - stones[0] + 1) - n + 1
        if stones[0] < stones[1] - 2 and stones[n - 1] - stones[1] == n - 2:
            return [2, maxi]
        if stones[n - 1] > stones[n - 2] + 2 and stones[n - 2] - stones[0] == n - 2:
            return [2, maxi]

        i, j = 0, 0
        mini = 2000000000
        while i < n:
            while j < n and stones[j] - stones[i] < n - 1:
                j += 1
            mini = min(mini, n - j + i)
            i += 1
        return [mini, maxi]