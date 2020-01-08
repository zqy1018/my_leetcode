class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0: return '0'
        flag, ans = 1, []
        if num < 0: 
            num = -num
            flag = -1
        while num:
            ans.append(str(num % 7))
            num //= 7
        if flag < 0: ans.append("-")
        return "".join(ans[: : -1])
            
