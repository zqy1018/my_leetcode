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
    vector<int> ans;
    int cnt;
    void dfs(TreeNode* root){
        if(root->left != NULL) dfs(root->left);
        ans.push_back(root->val);
        if(root->right != NULL) dfs(root->right);
    }
    void dfs2(TreeNode* root){
        if(root->left != NULL) dfs2(root->left);
        (root->val) = ans[cnt++];
        if(root->right != NULL) dfs2(root->right);
    }
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        int ss = 0;
        int n = ans.size();
        for (int i = n - 1; i >= 0; --i)
            ss += ans[i], ans[i] = ss;
        cnt = 0;
        dfs2(root);
        return root;
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
