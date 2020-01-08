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
    pair<TreeNode*, int> dfs(TreeNode* root, int dep){
        if (root == NULL) return make_pair(root, dep - 1);
        pair<TreeNode*, int> resl = dfs(root->left, dep + 1),  
            resr = dfs(root->right, dep + 1);
        if(resl.second == resr.second) return make_pair(root, resl.second);
        else {
            if (resl.second > resr.second) return resl;
            else return resr;
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root, 1).first;
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
