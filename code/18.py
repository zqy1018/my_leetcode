class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        len1 = len(nums)
        if len1 < 4:
            return []
        dict1, all_list, tot = {}, [], 0
        for i in range(0, len1 - 1):
            for j in range(i + 1, len1):
                if dict1.get(nums[i] + nums[j], -1) == -1:
                    all_list.append([])
                    all_list[tot].append((i, j))
                    dict1[nums[i] + nums[j]] = tot
                    tot += 1
                else:
                    res = dict1[nums[i] + nums[j]]
                    all_list[res].append((i, j))

        ans = set()         
        for i in range(0, len1 - 1):
            for j in range(i + 1, len1):
                addr = dict1.get(target - nums[i] - nums[j], -1)
                if addr >= 0 and addr < tot:
                    for k in all_list[addr]:
                        if i == k[0] or i == k[1] or j == k[0] or j == k[1]:
                            continue
                        a, b, c, d = nums[i], nums[j], nums[k[0]], nums[k[1]]
                        if a > b: a, b = b, a
                        if b > c: b, c = c, b
                        if c > d: c, d = d, c
                        if a > b: a, b = b, a
                        if b > c: b, c = c, b
                        if a > b: a, b = b, a
                        ans.add((a, b, c, d))
        ans_ = list(ans)
        return [list(t) for t in ans_]