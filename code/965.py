# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        if root == None: return True
        def trav(cur):
            if cur == None: return True
            if cur.val != root.val: return False
            return trav(cur.left) and trav(cur.right)   
        return trav(root)