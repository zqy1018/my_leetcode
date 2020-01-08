class Solution:
    def uncommonFromSentences(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: List[str]
        """
        from collections import Counter
        list1, list2 = A.split(), B.split()
        d1, d2 = Counter(list1), Counter(list2)
        return [v for v in d1 if d1[v] == 1 and d2.get(v) == None] + [v for v in d2 if d2[v] == 1 and d1.get(v) == None]