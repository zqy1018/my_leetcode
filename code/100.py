# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        def travell(curn, curn1):
            if curn == None or curn1 == None:
                return curn == None and curn1 == None
            if curn.val != curn1.val:
                return False
            return travell(curn.left, curn1.left) and travell(curn.right, curn1.right)
        return travell(p, q)
