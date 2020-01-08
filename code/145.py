# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root == None:
            return []
        ans = []
        def travell(curn):
            if curn.left != None:
                travell(curn.left)
            if curn.right != None:
                travell(curn.right)
            ans.append(curn.val)
            
        travell(root)
        return ans
