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

class Solution {
public:
    vector<int> val;
    int cnt, flag;
    void dfs2(TreeNode* root){
        if (root == NULL) return ;
        if (root->left == NULL && root->right == NULL){
            if (cnt >= val.size() || val[cnt] != root->val)
                flag = 0;
            ++cnt;
            return ;
        }
        dfs(root->left);
        dfs(root->right);
    }
    void dfs(TreeNode* root){
        if (root == NULL) return ;
        if (root->left == NULL && root->right == NULL){
            val.push_back(root->val);
            return ;
        }
        dfs(root->left);
        dfs(root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1);
        cnt = 0, flag = 1;
        dfs2(root2);
        return flag && cnt == val.size();
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
