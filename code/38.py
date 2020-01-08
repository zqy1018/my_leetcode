class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        pans = ["1"]
        for i in range(1, n):
            lst, cur, len1 = 0, 0, len(pans)
            cans = []
            while cur < len1:
                while cur < len1 and pans[lst] == pans[cur]:
                    cur += 1
                cans.append(str(cur - lst))
                cans.append(pans[lst])
                lst = cur
            pans = cans
        return "".join(pans)