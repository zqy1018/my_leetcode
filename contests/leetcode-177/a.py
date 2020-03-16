class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        import datetime
        dt1 = datetime.datetime(int(date1[: 4]), int(date1[5: 7]), int(date1[8: 10]))
        dt2 = datetime.datetime(int(date2[: 4]), int(date2[5: 7]), int(date2[8: 10]))

        dis = dt2 - dt1
        dis = dis.total_seconds()
        return int(dis / 86400)

a = Solution()  
print(a.daysBetweenDates("2019-06-29", "2019-06-30"))