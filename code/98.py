class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if root == None: return True
        flag = True
        def travell(root):
            nonlocal flag
            ffst, llst = None, None
            if root.left != None: 
                tp = travell(root.left)
                if ffst == None: ffst = tp[0]
                llst = tp[1]
                if tp[1] >= root.val:
                    flag = False
            if ffst == None: ffst = root.val
            llst = root.val
            if root.right != None: 
                tp = travell(root.right)
                if ffst == None: ffst = tp[0]
                llst = tp[1]
                if tp[0] <= root.val:
                    flag = False
            return ffst, llst
        travell(root)
        return flag
