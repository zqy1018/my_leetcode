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
    TreeNode* dfs(TreeNode* root){
        TreeNode *tmpl = NULL, *tmpr = NULL;
        if(root->left != NULL)
            tmpl = dfs(root->left);
        if(root->right != NULL)
            tmpr = dfs(root->right);
        if(tmpl != NULL){
            tmpl->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }else tmpl = root;
        if(tmpr == NULL)
            tmpr = tmpl;
        return tmpr;
    }
    void flatten(TreeNode* root) {
        if(root == NULL) return ;
        dfs(root);
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
