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
class Solution {
public:
    bool dfs(TreeNode *rtl, TreeNode *rtr){
        if(rtl->val != rtr->val) return false;
        if((rtl->left == NULL) ^ (rtr->right == NULL))
            return false;
        bool res = 1;
        if(rtl->left != NULL) res &= dfs(rtl->left, rtr->right);
        if((rtl->right == NULL) ^ (rtr->left == NULL))
            return false;
        if(rtl->right != NULL) res &= dfs(rtl->right, rtr->left);
        return res;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        if((root->left == NULL) ^ (root->right == NULL))
            return false;
        if(root->left != NULL)
            return dfs(root->left, root->right);
        return true;
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
