class Solution:
    def isStrobogrammatic(self, num: str) -> bool:
        if "2" in num or "5" in num or "4" in num or "3" in num or "7" in num:
            return False
        lis = list(num)
        return "".join(map(lambda x: "9" if x == "6" else ("6" if x == "9" else x), lis))