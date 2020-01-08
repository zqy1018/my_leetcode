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
    void dfs( TreeNode* root, string& ans ){
        ans += to_string( root->val );
        if ( root->left == NULL ){
            if ( root->right == NULL ) return;
            else 
                ans.push_back('('), ans.push_back(')'),
                ans.push_back('('), dfs( root->right, ans ), ans.push_back(')');
        }else{
            ans.push_back('('), dfs( root->left, ans ), ans.push_back(')');
            if ( root->right == NULL ) return;
            ans.push_back('('), dfs( root->right, ans ), ans.push_back(')');
        }
    }
    string tree2str(TreeNode* t) {
        if ( t == NULL ) return string();
        string ans;
        dfs( t, ans );
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
