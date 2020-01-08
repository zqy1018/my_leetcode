class Solution:
    def diStringMatch(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        ss = [0]
        up, down = 1, -1
        for i, ch in enumerate(S):
            if ch == "I":
                ss.append(up)
                up += 1
            else:
                ss.append(down)
                down -= 1
        for i, k in enumerate(ss):
            ss[i] = k - down
        return ss
            