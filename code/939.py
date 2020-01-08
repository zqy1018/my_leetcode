class Solution:
    def minAreaRect(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        set1 = set()
        ans, len1 = 3000000000, len(points)
        for i in points:
            set1.add((i[0], i[1]))
        for i in range(0, len1):
            x0, y0 = points[i][0], points[i][1]
            for j in range(i + 1, len1):
                x1, y1 = points[j][0], points[j][1]
                if x0 == x1 or y0 == y1:
                    continue
                else:
                    if (x0, y1) in set1 and (x1, y0) in set1:
                        ans = min(ans, abs((x1 - x0) * (y1 - y0)))
        return ans if ans != 3000000000 else 0