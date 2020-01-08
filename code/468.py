class Solution:
    def validIPAddress(self, IP: str) -> str:
        def judge(s):
            return True if str.startswith(s, "00") else False
            
        b1, b2 = IP.find("."), IP.find(":")
        if b1 != -1 and b2 == -1:
            lis = IP.split(".")
            if len(lis) != 4:
                return "Neither"
            for ss in lis:
                if not str.isdecimal(ss):
                    return "Neither"
                toi = int(ss)
                if toi < 0 or toi > 255 or judge(ss):
                    return "Neither"
            return "IPv4"
        elif b1 == -1 and b2 != -1:
            lis = IP.split(":")
            if len(lis) != 8:
                return "Neither"
            for ss in lis:
                if len(ss) > 4 or len(ss) == 0 or judge(ss):
                    return "Neither"
                for c in ss:
                    if (ord(c) < ord('0') or ord(c) > ord('9')) and \
                        (ord(c) < ord('A') or ord(c) > ord('F')) and \
                        (ord(c) < ord('a') or ord(c) > ord('f')):
                        return "Neither"
            return "IPv6"
        else:
            return "Neither"
        