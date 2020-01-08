class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        t = bin(n)[2:]
        return int(((32 - len(t)) * "0" + t)[: : -1], 2)