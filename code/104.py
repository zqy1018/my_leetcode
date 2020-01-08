# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        ans = 0
        def travell(root, dep):
            nonlocal ans
            ans = max(ans, dep)
            if root.left != None:
                travell(root.left, dep + 1)
            if root.right != None:
                travell(root.right, dep + 1)
        travell(root, 1)
        return ans