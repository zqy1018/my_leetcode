class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        ans = []
        
        for idx, s in enumerate(words):
            flag = False
            for idy, ss in enumerate(words):
                if idx != idy and s in ss:
                    flag = True
                    break
            if flag:
                ans.append(s)
        return ans