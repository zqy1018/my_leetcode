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
// 1 8 3 4 5 6 7 2 9
class Solution {
public:
    TreeNode *lst1, *targ1, *targ2;
    void dfs(TreeNode* root){
        if (root == NULL) return ;
        dfs(root->left);
        if (lst1 != NULL && lst1->val > root->val){
            if (targ1 == NULL) targ1 = lst1, targ2 = root;
            else targ2 = root;
        }
        lst1 = root;
        dfs(root->right);
    }
    void recoverTree(TreeNode* root) {
        lst1 = NULL, targ1 = targ2 = NULL;
        dfs(root);
        swap(targ1->val, targ2->val);
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
