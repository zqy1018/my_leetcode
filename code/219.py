class Solution:
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        dict1 = {}
        for i, num in enumerate(nums):
            id1 = dict1.get(num, -1)
            if id1 >= 0 and i - id1 <= k:
                return True
            dict1[num] = i
        return False