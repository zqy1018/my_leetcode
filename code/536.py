class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def str2tree(self, s: str) -> TreeNode:
        if not s:
            return None
        ll = len(s)

        def dfs(l):
            nonlocal s, ll
            x = 0
            cur = l
            while cur < ll and s[cur].isdigit():
                x = x * 10 + int(s[cur])
                cur += 1
            rt = TreeNode(x)
            if cur == ll or s[cur] == ')':
                return rt, cur

            rt.left, cur = dfs(cur + 1)
            cur += 1
            if cur == ll or s[cur] == ')':
                return rt, cur
            
            rt.right, cur = dfs(cur + 1)
            return rt, cur + 1
        ans, _ = dfs(0)
        return ans
            
a = Solution()
tr = a.str2tree("4(1)")
print(tr.left.val)
