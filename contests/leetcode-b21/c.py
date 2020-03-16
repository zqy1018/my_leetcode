
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def longestZigZag(self, root: TreeNode) -> int:
        ans = 0
        if root == None:
            return 0

        def dfs(cur):
            nonlocal ans
            cur.lll = 0
            cur.rrr = 0
            if cur.left != None:
                dfs(cur.left)
                cur.lll = max(cur.lll, cur.left.rrr + 1)
            if cur.right != None:
                dfs(cur.right)
                cur.rrr = max(cur.rrr, cur.right.lll + 1)
            ans = max(ans, cur.lll) 
            ans = max(ans, cur.rrr)

        dfs(root)
        return ans
            