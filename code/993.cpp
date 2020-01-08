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
	int xx, yy, dx, dy;
	void dfs(TreeNode* root, int d){
		if(root == NULL) return ;
		if(root->val == xx) dx = d;
		if(root->val == yy) dy = d;
		dfs(root->left, d + 1);
		dfs(root->right, d + 1);
		if(root->left != NULL && root->right != NULL && 
			((root->left->val == xx && root->right->val == yy) || 
			(root->right->val == xx && root->left->val == yy)))
			dx = dy = -1;
	}
    bool isCousins(TreeNode* root, int x, int y) {
		xx = x, yy = y;
		dx = dy = -1;
		dfs(root, 0);
		return dx < 0 ? false: dx == dy;
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
