class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        def oord(x):
            return ord(x) - 97
        
        dict1 = {}
        list1 = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
            31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
            73, 79, 83, 89, 97, 101]
        for i, s in enumerate(strs):
            res = 1
            for c in s:
                res *= list1[oord(c)]
            
            if dict1.get(res, -1) == -1:
                dict1[res] = [i]
            else:
                dict1[res].append(i)
        
        ans = [[strs[i] for i in v] for v in dict1.values()]
        return ans

