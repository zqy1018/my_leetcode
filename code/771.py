class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        return sum([1 for c in S if c in J])
        