class Solution:
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        nums3, len1 = nums2[: ], len(nums2)
        dict1 = {}
        nums3.sort()
        for i in nums3:
            idx = nums2.index(i)
            if idx == len1 - 1:
                dict1[i] = -1
            else:
                dict1[i] = nums2[idx + 1]
            del nums2[idx]
            len1 -= 1
        len2 = len(nums1)
        for i in range(0, len2):
            nums1[i] = dict1[nums1[i]]
        return nums1