class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        dom = {}
        for str1 in cpdomains:
            lis = str1.split(' ')
            num, lis_str = int(lis[0]), lis[1].split('.')
            len1, stre = len(lis_str), lis_str[-1]
            for i in range(len1 - 1, -1, -1):
                stre = lis_str[i] + "." + stre
                if dom.get(stre, -1) == -1:
                    dom[stre] = num
                else:
                    dom[stre] += num
        ans = []
        for k, v in dom.items():
            ans.append(str(v) + " " + k)

        return ans
