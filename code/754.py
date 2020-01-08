class Solution:
    def reachNumber(self, target):
        """
        :type target: int
        :rtype: int
        """
        if target == 0:
            return 0
        if target < 0:
            target = -target
        
        l, r = 1, target
        while l < r:
            mid = (l + r) >> 1
            if target <= mid * (mid + 1) // 2:
                r = mid
            else:
                l = mid + 1
        
        return ((l + 1) >> 1) << 1 | 1 if (((l + 1) >> 1) - target) & 1 else l