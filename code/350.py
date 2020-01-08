class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        dict1 = {}
        if len(nums1) >= len(nums2):
            nums1, nums2 = nums2, nums1
        for i in nums1:
            if not i in dict1:
                dict1[i] = 1
            else: 
                dict1[i] += 1
        ans = []
        for i in nums2:
            if i in dict1:
                dict1[i] -= 1
                ans.append(i)
                if dict1[i] == 0:
                    del dict1[i]
        return ans