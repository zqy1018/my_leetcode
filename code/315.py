class Solution(object):
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        list1, len1 = list(enumerate(nums)), len(nums)
        list1.sort(key = lambda x: x[1])
        cnt, ans = [0 for i in range(len1 + 1)], [0 for i in range(len1)]
        
        def lowbit(x):
            return x & (-x)
        def ask(r):
            res = 0
            while r > 0:
                res += cnt[r]
                r -= lowbit(r)
            return res
        def modify(k, r):
            while r <= len1:
                cnt[r] += k
                r += lowbit(r)

        for tp in list1:
            ans[tp[0]] = ask(len1) - ask(tp[0] + 1)
            modify(1, tp[0])
        return ans