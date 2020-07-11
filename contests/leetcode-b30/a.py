class Solution:
    def reformatDate(self, date: str) -> str:
        d, m, y = date.split()
        if m == 'Jan':
            m = 1
        elif m == 'Feb':
            m = 2
        elif m == 'Mar':
            m = 3
        elif m == 'Apr':
            m=4
        elif m=='May':
            m=5
        elif m=='Jun':
            m = 6
        if m == 'Jul':
            m = 7
        elif m == 'Aug':
            m = 8
        elif m == 'Sep':
            m = 9
        elif m == 'Oct':
            m=10
        elif m=='Nov':
            m=11
        elif m=='Dec':
            m = 12
        if d[1].isdigit():
            d = int(d[: 2])
        else:
            d = int(d[0])
        ans = y + "-" + ("0" if m < 10 else "") + "-" + str(d)
        return ans