# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if root == None:
            return False
        def travell(curn, tot):
            tot += curn.val
            if curn.left == None:
                if curn.right == None:
                    return tot == sum
                else:
                    return travell(curn.right, tot)
            else:
                if curn.right == None:
                    return travell(curn.left, tot)
                else:
                    return travell(curn.left, tot) or travell(curn.right, tot)
        return travell(root, 0)