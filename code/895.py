class FreqStack:

    def __init__(self):
        self.freq = {}
        self.maxi = 0
        self.stacks = {}

    def push(self, x: int) -> None:
        if not x in self.freq:
            self.freq[x] = 1
        else:
            self.freq[x] += 1
        f = self.freq[x]
        if f > self.maxi:
            self.maxi = f
            if not self.maxi in self.stacks:
                self.stacks[self.maxi] = []
        self.stacks[f].append(x)

    def pop(self) -> int:
        x = self.stacks[self.maxi].pop()
        self.freq[x] -= 1
        if not self.stacks[self.maxi]:
            self.maxi -= 1
        return x


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(x)
# param_2 = obj.pop()