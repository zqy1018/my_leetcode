class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        from functools import cmp_to_key
        def ccmp(x, y):
            if x + y > y + x:
                return -1
            elif x + y == y + x:
                return 0
            return 1 
        nums = [str(num) for num in nums]
        nums.sort(key = cmp_to_key(ccmp))
        if nums and nums[0] == '0':
            return '0'
        return "".join(nums)