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
    pair<int, int> dfs(TreeNode *root){
        int f0 = 0, f1 = root->val;
        if(root->left != NULL){
            pair<int, int> fl = dfs(root->left);
            f0 += max(fl.first, fl.second);
            f1 += fl.first;
        }
        if(root->right != NULL){
            pair<int, int> fl = dfs(root->right);
            f0 += max(fl.first, fl.second);
            f1 += fl.first;
        }
        return make_pair(f0, f1);
    }
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        pair<int, int> ans = dfs(root);
        return max(ans.first, ans.second);
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
