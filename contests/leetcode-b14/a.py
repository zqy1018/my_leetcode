class Solution:
    def toHexspeak(self, num: str) -> str:
        a = int(num)
        b = hex(a)[2: ]
        lis = list(b)
        l = len(lis)
        for i in range(l):
            if lis[i] == '0':
                lis[i] = "O"
            elif lis[i] == '1':
                lis[i] = 'I'
            elif lis[i].isdigit():
                return "ERROR"
            else:
                lis[i] = lis[i].toupper()
        return "".join(lis)
