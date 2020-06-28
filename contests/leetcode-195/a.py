class Solution:
    def isPathCrossing(self, path: str) -> bool:
        st = set()
        x, y = 0, 0
        d = dict()
        st.add((x, y))
        n = len(path)
        for i in range(n):
            if path[i] == 'N':
                y += 1
            elif path[i] == 'S':
                y -= 1
            elif path[i] == 'W':
                x -= 1
            elif path[i] == 'E':
                x += 1
            if (x, y) in st:
                return True
            st.add((x, y))
        return False