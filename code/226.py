# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root == None: return root
        def rev(curn):
            if curn.left != None:
                rev(curn.left)
            if curn.right != None:
                rev(curn.right)
            curn.left, curn.right = curn.right, curn.left
        rev(root)
        return root