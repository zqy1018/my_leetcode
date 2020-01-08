class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        ans = []
        tmp = []
        def dfs(rt):
            tmp.append(str(rt.val))
            if rt.left != None:
                dfs(rt.left)
                if rt.right != None:
                    dfs(rt.right)
            else:
                if rt.right != None:
                    dfs(rt.right)
                else:
                    ans.append("->".join(tmp))
            tmp.pop()

        if root == None:
        	return ans
        else:
        	dfs(root)
        	return ans
