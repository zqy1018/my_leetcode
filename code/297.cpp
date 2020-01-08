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

class Codec {
public:

    void dfs( TreeNode* root, string& ans ){
        if (root == NULL) {
            ans.push_back(' ');
            ans.push_back('#');
            return ;
        }
        ans.push_back(' ');
        ans += to_string( root->val );
        dfs( root->left, ans );
        dfs( root->right, ans );
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans("");
        dfs( root, ans );
        return ans;
    }

    pair<TreeNode*, int> dfs2( string& data, int l ){
        ++l;
        if ( data[l] == '#' ) return make_pair( ( TreeNode* ) NULL, l + 1 );
        int x = 0, flag = 1;
        if ( data[l] == '-' ) flag = -1, ++l;
        while ( data[l] != ' ' )
            x = x * 10 + data[l] - '0', ++l;
        x = x * flag;
        TreeNode* root = new TreeNode(x);
        pair<TreeNode*, int> res = dfs2 ( data, l );
        root->left = res.first, l = res.second;
        res = dfs2 ( data, l );
        root->right = res.first, l = res.second;
        return make_pair( root, l );
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return dfs2( data, 0 ).first;
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
