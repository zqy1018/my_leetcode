class Solution:
    def divisorGame(self, N: int) -> bool:
        lis = [0] * 1001
        vis = [0] * 1001
        lis[1] = 1
        lis[2] = 1
        for i in range(2, 1001):
            if vis[i] == 0:
                for j in range(i + i, 1001, i):
                    vis[j] = 1
        for i in range(3, 1001):
            flag = 0
            for j in range(1, i):
                if i % j == 0:
                    if lis[i - j] == 0:
                        flag = 1
            lis[i] = flag
        return lis[N]