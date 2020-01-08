# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        def mmerge(cur1, cur2):
            if cur1 == None and cur2 == None: return None
            curt = TreeNode(0)
            if cur1 != None: curt.val += cur1.val
            if cur2 != None: curt.val += cur2.val
            curt.left = mmerge(cur1.left if cur1 != None else None, cur2.left if cur2 != None else None)
            curt.right = mmerge(cur1.right if cur1 != None else None, cur2.right if cur2 != None else None)
            return curt
                
        return mmerge(t1, t2)
