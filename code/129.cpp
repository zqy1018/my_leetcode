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
    int dfs(TreeNode *rt, int x){
        if(rt->left == NULL && rt->right == NULL)
            return x * 10 + rt->val;
        int res = 0;
        if(rt->left != NULL) res += dfs(rt->left, x * 10 + rt->val);
        if(rt->right != NULL) res += dfs(rt->right, x * 10 + rt->val);
        return res;
    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = dfs(root, 0);
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
