class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        from collections import Counter
        cc = Counter(arr)
        c2 = Counter(list(cc.values))
        for v in values:
            if v >= 2: 
                return False
        return True