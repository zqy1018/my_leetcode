class Solution:
    def isMajorityElement(self, nums: List[int], target: int) -> bool:
        import collections
        ct = collections.Counter(nums)
        len1 = len(nums)
        return ct[target] > (len1 // 2)