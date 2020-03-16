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
    vector<vector<int>> ans;
    int dep;
    bool dfs(TreeNode* cur, int d){
        if (cur->left == nullptr && cur->right == nullptr){
            ans[0].push_back(cur->val);
            return d == dep;
        }
        bool res = false;
        if (cur->left != nullptr)
            res |= dfs(cur->left, d + 1);
        if (cur->right != nullptr)
            res |= dfs(cur->right, d + 1);
        ans[dep - d + res - 1].push_back(cur->val);
        return res;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        TreeNode* tmp = root;
        dep = 0;
        while (tmp != nullptr)
            ans.push_back(vector<int>()), 
            tmp = tmp->left, ++dep;
        dfs(root, 1);
        return ans;
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
