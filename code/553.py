class Solution:
    def optimalDivision(self, nums: List[int]) -> str:
        if len(nums) == 1: return str(nums[0])
        if len(nums) == 2: return str(nums[0]) + "/" + str(nums[1])
        s = str(nums[0]) + "/("
        for i in nums[1: -1]:
            s += str(i) + "/"
        s += str(nums[-1]) + ")"
        return s