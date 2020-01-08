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
bool isLeaf(TreeNode* root) {
    return root->left == NULL && root->right == NULL;
}
class Solution {
public:
    int lim;
    int dfs(TreeNode* cur, int acc){
        if (cur == NULL) return INT_MIN;
        if (isLeaf(cur)) return cur->val;
        acc += cur->val;
        int res = INT_MIN;
        int resl = dfs(cur->left, acc), resr = dfs(cur->right, acc);
        if (resl < lim - acc) cur->left = NULL;
        if (resr < lim - acc) cur->right = NULL;
        res = max(resl, resr) + cur->val;
        return res;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        lim = limit;
        TreeNode* rt = new TreeNode(0);
        rt->left = root;
        dfs(rt, 0);
        return rt->left;
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
