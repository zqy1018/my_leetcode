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
    void dfs( TreeNode* root, int v, int d, int dep ){
        if ( dep == d - 1 ){
            TreeNode* niul = new TreeNode( v ), *niur = new TreeNode( v );
            niul->left = root->left, niur->right = root->right;
            root->right = niur, root->left = niul;
            return ;
        }
        dfs( root->left, v, d, dep + 1 );
        dfs( root->right, v, d, dep + 1 );
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if ( d == 1 ) {
            TreeNode* niu = new TreeNode( v );
            niu->left = root;
            return niu;
        }
        dfs( root, v, d, 1 );
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
