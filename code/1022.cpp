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
    int dfs(TreeNode* cur, int d){
        if(cur->left == NULL && cur->right == NULL)
            return (d + d + cur->val) % 1000000007;
        int res = 0;
        if(cur->left != NULL)
            res += dfs(cur->left, (d + d + cur->val) % 1000000007), 
            res %= 1000000007;
        if(cur->right != NULL)
            res += dfs(cur->right, (d + d + cur->val) % 1000000007), 
            res %= 1000000007;
        return res;
    }
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
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
