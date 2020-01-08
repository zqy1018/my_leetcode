class Solution:
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        
        def oord(x):
            return ord(x) - 97

        list1, num = [0] * 26, 0
        for i in p:
            idx = oord(i)
            list1[idx] += 1
            if list1[idx] == 1: num += 1
            
        list2, cnt = [0] * 26, 0

        def calc(o, x):
            nonlocal cnt, list2
            idx = oord(x)
            if list2[idx] == list1[idx]: 
                cnt = cnt - 1
            list2[idx] += o
            if list2[idx] == list1[idx]: 
                cnt = cnt + 1

        len1, len2, ans = len(p), len(s), []
        
        if len1 > len2: return ans

        for i in range(0, len1):
            calc(1, s[i: i + 1])

        if cnt == num:
            ans.append(0)
        
        for i in range(len1, len2):
            calc(-1, s[i - len1: i - len1 + 1])
            calc(1, s[i: i + 1])
            if cnt == num:
                ans.append(i - len1 + 1)

        return ans