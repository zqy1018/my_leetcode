#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isLeaf(TreeNode* root) {
    return root->left == NULL && root->right == NULL;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int siz1;
    bool flag;
    TreeNode* tmp;
    int dfs(TreeNode* cur){
        if (cur == NULL) return 0;
        return 1 + dfs(cur->left) + dfs(cur->right);
    }
    bool judge(TreeNode* s, TreeNode* t){
        if (s == NULL && t == NULL) return true;
        if (s == NULL || t == NULL) return false;
        return s->val == t->val && judge(s->left, t->left) && judge(s->right, t->right);
    }
    int dfs2(TreeNode* cur){
        if (cur == NULL) return 0;
        int siz = 1 + dfs2(cur->left) + dfs2(cur->right);
        if (siz == siz1 && cur->val == tmp->val)
            flag = flag || judge(cur, tmp);
        return siz;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        siz1 = dfs(t), flag = false;
        tmp = t;
        dfs2(s);
        return flag;
    }
};
Solution sol;
void init(){
    
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
