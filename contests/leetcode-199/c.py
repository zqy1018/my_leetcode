class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countPairs(self, root: TreeNode, distance: int) -> int:
        ans = 0
        def dfs(t, dep):
            nonlocal ans, distance
            t.d = dep
            t.flag = False
            t.lfs = []
            if t.left != None:
                dfs(t.left, dep + 1)
                t.flag = True
            if t.right != None:
                dfs(t.right, dep + 1)
                t.flag = True

            if t.flag == False:
                t.lfs.append(t.d)
            else:
                if t.left != None and t.right != None:
                    for x in t.left.lfs:
                        for y in t.right.lfs:
                            if x + y - 2 * dep <= distance:
                                ans += 1
                if t.left != None:
                    t.lfs += t.left.lfs
                if t.right != None:
                    t.lfs += t.right.lfs
        dfs(root, 1)
        return ans

                    