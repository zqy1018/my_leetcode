class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        lis = [s.split(",") for s in transactions]
        l = len(transactions)
        ans = []
        for i in range(0, l):
            if int(lis[i][2]) > 1000:
                ans.append(transactions[i])
                continue
            for j in range(0, l):
                if lis[i][0] == lis[j][0] and lis[i][3] != lis[j][3] and abs(int(lis[i][1]) - int(lis[j][1])) <= 60:
                    ans.append(transactions[i])
                    break
        return ans
                
