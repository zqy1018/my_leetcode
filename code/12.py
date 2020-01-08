class Solution:
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        th, num = num // 1000, num % 1000
        hu, num = num // 100, num % 100
        te, num = num // 10, num % 10
        ans = ["M"] * th
        if hu == 9: ans.extend(["C", "M"])
        elif hu == 4: ans.extend(["C", "D"])
        else:
            if hu >= 5: 
                ans.append("D")
                hu -= 5
            ans.extend(["C"] * hu)

        if te == 9: ans.extend(["X", "C"])
        elif te == 4: ans.extend(["X", "L"])
        else:
            if te >= 5: 
                ans.append("L")
                te -= 5
            ans.extend(["X"] * te)

        if num == 9: ans.extend(["I", "X"])
        elif num == 4: ans.extend(["I", "V"])
        else:
            if num >= 5: 
                ans.append("V")
                num -= 5
            ans.extend(["I"] * num)
        
        return "".join(ans)