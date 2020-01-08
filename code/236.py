class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root == None: return None
        dp, dq = 0, 0
        def getD(root, d):
            nonlocal p, q, dp, dq
            if root == p: dp = d
            if root == q: dq = d
            if root.left != None:
                root.left.fa = root
                getD(root.left, d + 1)
            if root.right != None:
                root.right.fa = root
                getD(root.right, d + 1)
        getD(root, 1)
        root.fa = 0
        while dp > dq: 
            p = p.fa
            dp -= 1
        while dq > dp: 
            q = q.fa
            dq -= 1
        while p != q:
            p = p.fa
            q = q.fa
        return p
