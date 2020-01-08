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

class Solution {
public:
    TreeNode* build(int pl, int pr, int il, int ir, vector<int>& preorder, vector<int>& inorder){
        if(pl > pr) return NULL;
        TreeNode *root = new TreeNode(preorder[pl]);
        int cur = il;
        while(cur <= ir && inorder[cur] != root->val)
            ++cur;
        root->left = build(pl + 1, pl + cur - il, il, cur - 1, preorder, inorder);
        root->right = build(pl + 1 + cur - il, pr, cur + 1, ir, preorder, inorder);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort( inorder.begin(), inorder.end() ) ;
        int n = preorder.size();
        return build(0, n - 1, 0, n - 1, preorder, inorder);
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
