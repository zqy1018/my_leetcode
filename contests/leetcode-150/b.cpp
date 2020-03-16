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
    vector<int> ddep;
    int maxde;
    void dfs(TreeNode* root, int dep)   {
        if (root == NULL) return ;
        ddep[dep] += root->val;
        maxde = max(maxde, dep);
        dfs(root->left, dep + 1);
        dfs(root->right, dep + 1);
    }
    int maxLevelSum(TreeNode* root) {
        ddep = vector<int>(10001, 0);
        maxde = 0;
        dfs(root, 1);
        int maxi = INT_MIN, pos = -1;
        for (int i = 1; i <= maxde; ++i){
            if (ddep[i] > maxi)
                maxi = ddep[i], pos = i;
        }
        return pos;
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
