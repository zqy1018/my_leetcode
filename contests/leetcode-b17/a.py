class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = []
        for i in range(n, 2):
            print([nums[i + 1]] * nums[i])
            ans.extend([nums[i + 1]] * nums[i])
            print(ans)
        return ans