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

class CBTInserter {
public:
    TreeNode* rt;
    int siz;

    void dfs ( TreeNode* root ){
        if ( root == NULL ) return ;
        dfs ( root->left );
        ++siz;
        dfs ( root->right );
    }

    CBTInserter(TreeNode* root) {
        rt = root;
        siz = 0;
        dfs( root );
    }
    
    int insert(int v) {
        int t = ++siz, q = 1;
        TreeNode *cur = rt, *niu = new TreeNode(v);
        while ( t > 1 )
            ( t & 1 ) ? ( q = q << 1 | 1 ): ( q = q << 1 ), t >>= 1;
        while ( q >= 4 )
            cur = ( q & 1 ) ? cur->right: cur->left, q >>= 1;
        if ( q & 1 ) cur->right = niu;
        else cur->left = niu;
        return cur->val;
    }
    
    TreeNode* get_root() {
        return rt;
    }
};
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
