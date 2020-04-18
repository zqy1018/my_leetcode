class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def minimalExecTime(self, root: TreeNode) -> float:

        def dfs(cur):
            cur.sm = cur.val
            if cur.left != None and cur.right != None:
                dfs(cur.left)
                dfs(cur.right)
                cur.sm += cur.left.sm + cur.right.sm
                gl = cur.left.sm - cur.left.f
                gr = cur.right.sm - cur.right.f
                mid = (cur.right.sm - cur.left.sm) / 2
                t = 0
                if mid < -gl:
                    t = -gl
                elif mid > gr:
                    t = gr
                else:
                    t = mid
                cur.f = cur.val + max(cur.left.sm + t, cur.right.sm - t)
                cur.f = min(cur.f, cur.val + cur.left.f + cur.right.f)
            elif cur.left != None:
                dfs(cur.left)
                cur.sm += cur.left.sm
                cur.f = cur.val + cur.left.f
            elif cur.right != None:
                dfs(cur.right)
                cur.sm += cur.right.sm
                cur.f = cur.val + cur.right.f
            else:
                cur.f = cur.val

        dfs(root)
        return root.f
            