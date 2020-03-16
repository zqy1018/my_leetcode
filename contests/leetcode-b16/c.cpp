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
    int maxi;
    void dfs(TreeNode* cur, int dep) {
        if (cur == NULL) return ;
        maxi = max(maxi, dep);
        dfs(cur->left, dep + 1);
        dfs(cur->right, dep + 1);
    }
    int dfs2(TreeNode* cur, int dep) {
        if (cur == NULL) return 0;
        if (cur->left == NULL && cur->right == NULL && dep == maxi)
            return cur->val;
        return dfs2(cur->left, dep + 1) + dfs2(cur->right, dep + 1);
    }
    int deepestLeavesSum(TreeNode* root) {
        maxi = 0;
        dfs(root, 1);
        return dfs2(root, 1);
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
