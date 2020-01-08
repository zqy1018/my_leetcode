class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :type target: int
        """
        ans = set()
        len1 = len(nums) 
        nums = [nums[i] for i in range(len1) if nums[: i].count(nums[i]) < 3]
        len1 = len(nums) 
        
        if len1 < 3:
            return []
        dict1 = {}
        for i in range(0, len1):
            if dict1.get(nums[i], -1) == -1:
                dict1[nums[i]] = [i]
            else:
                dict1[nums[i]].append(i)

        for i in range(0, len1 - 1):
            for j in range(i + 1, len1):
                addr = dict1.get(-nums[i] - nums[j], -1)
                if addr != -1:
                    for k in addr:
                        if i == k or j == k:
                            continue
                        a, b, c = nums[i], nums[j], nums[k]
                        if a > b: a, b = b, a
                        if b > c: b, c = c, b
                        if a > b: a, b = b, a
                        ans.add((a, b, c))
        ans_ = list(ans)
        return [list(t) for t in ans_]