class Solution:
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        prime, cnt, vis = [], 0, [0] * n
        for i in range(2, n):
            if not vis[i]:
                prime.append(i)
                cnt += 1
            for j in range(0, cnt):
                if i * prime[j] >= n: break
                vis[i * prime[j]] = 1
                if i % prime[j] == 0: break
        return cnt

a = Solution()
print(a.countPrimes(1500000))