class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        list1 = [0] * 129
        for i in s:
            list1[ord(i)] += 1
        ans, flag = 0, 0
        for i in range(0, 128):
            ans += list1[i]
            if list1[i] & 1:
                ans -= 1
                flag = 1
        return ans + flag
        
        