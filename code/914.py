class Solution:
    def hasGroupsSizeX(self, deck):
        """
        :type deck: List[int]
        :rtype: bool
        """
        def gcd(a, b):
            return a if b == 0 else gcd(b, a % b)
        from collections import Counter
        from functools import reduce
        d1 = Counter(deck)
        list1 = []
        for k in d1:
            list1.append(d1[k])
        return reduce(gcd, list1) >= 2