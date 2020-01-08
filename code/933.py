class RecentCounter:

    def __init__(self):
        self.lst = []
        self.cur = 0
        self.len1 = 0
        

    def ping(self, t):
        """
        :type t: int
        :rtype: int
        """
        self.lst.append(t)
        self.len1 += 1
        while self.cur < self.len1 and self.lst[self.cur] < t - 3000:
            self.cur += 1
        return self.len1 - self.cur

        


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)