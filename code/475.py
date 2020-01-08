class Solution(object):
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        if houses == []: return 0
        len1, len2 = len(houses), len(heaters)
        houses.sort()
        heaters.sort()
        ans, cur = 0, 0
        for i in range(0, len1):
            t = cur
            while t < len2 and abs(houses[i] - heaters[t]) > ans and heaters[t] <= houses[i] + ans:
                t += 1
            if t == len2:
                ans = max(ans, abs(heaters[len2 - 1] - houses[len1 - 1]))
                break
            else:
                if abs(houses[i] - heaters[t]) > ans:
                    ans = min(abs(houses[i] - heaters[t - 1]), abs(houses[i] - heaters[t]))
                cur = t
        return ans