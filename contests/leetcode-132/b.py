# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        def dfs(root):
            ansh = -1
            mini, maxi = 100001, -1
            if root.left != None:
                ansl = dfs(root.left)
                ansh = max(ansh, ansl[0])
                mini = min(mini, ansl[1])
                maxi = max(maxi, ansl[2])
            if root.right != None:
                ansr = dfs(root.right)
                ansh = max(ansh, ansr[0])
                mini = min(mini, ansr[1])
                maxi = max(maxi, ansr[2])
            if mini <= 100001:
                ansh = max(ansh, abs(mini - root.val))
            if maxi >= 0:
                ansh = max(ansh, abs(maxi - root.val))
            mini = min(mini, root.val)
            maxi = max(maxi, root.val)
            return (ansh, mini, maxi)
        ans = dfs(root)
        return ans[0]

