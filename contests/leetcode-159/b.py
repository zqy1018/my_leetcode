class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        l = len(folder)
        folder.sort()
        st = set()
        for s in folder:
            ll = len(s)
            flag = True
            if s in st:
                continue
            for j in range(ll - 1, 1, -1):
                if s[j] == '/':
                    if s[0: j] in st:
                        flag = False
                        break
            if flag:
                st.add(s)
        return list(st)