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
    int ans;
    int dfs(TreeNode *root){
        if(root == NULL) return -2147483648;
        int ll = max(0, dfs(root->left));
        int rr = max(0, dfs(root->right));
        ans = max(ans, root->val + ll + rr);
        return root->val + max(ll, rr);
    } 
    int maxPathSum(TreeNode* root) {
        ans = -2147483648;
        dfs(root);
        return ans;
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
