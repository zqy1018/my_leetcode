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
int a1[5005], a2[5005], cnt1, cnt2;
class Solution {
public:
    void dfs(TreeNode* cur) {
        if (cur == NULL) return;
        dfs(cur->left);
        a1[cnt1++] = cur->val;
        dfs(cur->right);
    }
    void dfs2(TreeNode* cur) {
        if (cur == NULL) return;
        dfs2(cur->left);
        a2[cnt2++] = cur->val;
        dfs2(cur->right);
    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        cnt1 = cnt2 = 0;
        dfs(root1);
        dfs2(root2);
        for (int i = 0; i < cnt1; ++i){
            int bb = lower_bound(a2, a2 + cnt2, target - a1[i]) - a2;
            if (bb >= 0 && bb <= cnt2 && a1[i] + a2[bb] == target)
                return true;
        }
        return false;
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
