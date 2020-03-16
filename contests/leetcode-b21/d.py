class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def maxSumBST(self, root: TreeNode) -> int:
        if root == None: return True
        ans = -1600000000

        def travell(root):
            nonlocal ans
            ffst, llst, sm, canbe = None, None, root.val, True
            if root.left != None: 
                tp = travell(root.left)
                if ffst == None: ffst = tp[0]
                llst = tp[1]
                sm += tp[2]
                if tp[1] >= root.val or not tp[3]:
                    canbe = False
            if ffst == None: ffst = root.val
            llst = root.val
            if root.right != None: 
                tp = travell(root.right)
                if ffst == None: ffst = tp[0]
                llst = tp[1]
                sm += tp[2]
                if tp[0] <= root.val or not tp[3]:
                    canbe = False
            if canbe:
                ans = max(ans, sm)
            return ffst, llst, sm, canbe
        travell(root)
        return ans
