class MajorityChecker:

    def __init__(self, arr: List[int]):
        self.ar = arr

    def query(self, left: int, right: int, threshold: int) -> int:
        import collections
        ct = collections.Counter(self.ar[left: right + 1])
        k, v = ct.most_common(1)
        if v >= threshold:
            return k
        return -1


# Your MajorityChecker object will be instantiated and called as such:
# obj = MajorityChecker(arr)
# param_1 = obj.query(left,right,threshold)