class Solution:
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        i, j = 0, len(numbers) - 1
        while True:
            t = numbers[i] + numbers[j]
            if t == target:
                return [i + 1, j + 1]
            else:
                if t > target:
                    j -= 1
                else:
                    i += 1
