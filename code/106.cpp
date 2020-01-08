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
    TreeNode* build(int pl, int pr, int il, int ir, vector<int>& postorder, vector<int>& inorder){
        if(pl > pr || il > ir) return NULL;
        TreeNode *root = new TreeNode(postorder[pr]);
        int cur = il;
        while(cur <= ir && inorder[cur] != root->val)
            ++cur;
        root->left = build(pl, pl + cur - il - 1, il, cur - 1, postorder, inorder);
        root->right = build(pl + cur - il, pr - 1, cur + 1, ir, postorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        return build(0, n - 1, 0, n - 1, postorder, inorder);
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
