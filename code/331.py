class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        lst = preorder.split(",")
        deg = 1

        for idx, s in enumerate(lst):
            if deg == 0:
                return False
            deg += -1 if s == '#' else 1

        return deg == 0