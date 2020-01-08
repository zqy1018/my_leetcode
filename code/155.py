class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data = []
        self.len1 = 0
        

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        if self.len1 == 0:
            self.data.append((x, x))
        else:
            self.data.append((min(x, self.data[-1][0]), x))
        self.len1 += 1
        

    def pop(self):
        """
        :rtype: void
        """
        self.data.pop()
        self.len1 -= 1

    def top(self):
        """
        :rtype: int
        """
        return self.data[-1][1]
        

    def getMin(self):
        """
        :rtype: int
        """
        return self.data[-1][0]

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()