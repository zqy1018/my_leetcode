class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def solve(cur):
            nonlocal nums
            if cur == 1:
                return [[nums[0]]]
        
            list1 = solve(cur - 1)
            list2 = []
            for i in list1:
                for p in range(0, cur):
                    list2.append(i[: p] + [nums[cur - 1]] + i[p: ])

            return list2
        
        return solve(len(nums))