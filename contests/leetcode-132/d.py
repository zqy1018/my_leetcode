# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        lis2 = S.split('-')
        lis3 = []
        for i in lis2:
            if i != '':
                lis3.append(int(i))
        leen = len(S)
        def dfs(l, r, d):
            # print(l, r, d, root)
            nonlocal cnt
            if l > r:
                return None
            nd = TreeNode(0)
            i = l
            p1 = 0
            pp1 = 0
            flag = 0
            while i <= r:
                if S[i] == '-':
                    tot = 0
                    while S[i] == '-':
                        tot += 1
                        i += 1
                    if tot == d:
                        if flag == 0:
                            while i <= r and S[i] != '-':
                                pp1 = pp1 * 10 + int(S[i])
                                i += 1
                            p1 = i
                            flag = 1
                        else:
                            lis[root].left = lis[cnt]
                            lis[cnt].val = pp1
                            print(pp1)
                            dfs(p1, i - d - 1, d + 1, cnt)
                            cnt += 1
                            pp2 = 0
                            while i <= r and S[i] != '-':
                                pp2 = pp2 * 10 + int(S[i])
                                i += 1
                            lis[root].right = lis[cnt]
                            lis[cnt].val = pp2
                            dfs(i, r, d + 1, cnt)
                            cnt += 1
                            return 
                else:
                    i += 1
            if flag == 1:
                lis[root].left = lis[cnt]
                lis[cnt].val = pp1
                lis[root].right = None
                dfs(p1, r, d + 1, cnt)
                cnt += 1

        def dfs2(root, cur):
            root.val = lis3[cur]
            siz = 0
            if root.left != None:
                siz = dfs2(root.left, cur + 1)
            if root.right != None:
                siz += dfs2(root.right, cur + siz + 1)
            siz += 1
            return siz
        rooot = dfs(1, leen - 1, 1)
        rooot.val = lis3[0]
        
        # dfs2(lis[0], 0)
        return rooot

A = Solution()
aa = A.recoverFromPreorder("1-2--3--4-5--6--7")
for i in aa[: 8]:
    print(i.val)