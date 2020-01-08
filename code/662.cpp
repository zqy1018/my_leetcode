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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<unsigned long long> cnt;
    unsigned long long ans;
    void dfs( TreeNode* root, int dep, unsigned long long idx ){
        if ( root == NULL ) return ;
        if ( dep > cnt.size() )
            cnt.push_back( idx );
        else ans = max( ans, idx - cnt[dep - 1] );
        dfs( root->left, dep + 1, idx << 1 );
        dfs( root->right, dep + 1, idx << 1 | 1 );
    }
    int widthOfBinaryTree(TreeNode* root) {
        ans = 0;
        dfs( root, 1, 1 );
        return ans + 1;
    }
};
/*
[0, 0, 0, 0, null, null, 0, 0, null, null, 0, 
            0, null, null, 0, 0, null, null, 0, 
            0, null, null, 0, 0, null, null, 0, 
            0, null, null, 0, 0, null, null, 0, 
            0, null, null, 0, 0, null, null, 0, 
            0, null, null, 0, 0, null, null, 0,
            0, null, null, 0, 0, null, null, 0, 
            0, null, null, 0, 0, null, null, 0, 
            0, null, null, 0, 0, null, null, 0, 
            0, null, null, 0, 0, null, null, 0, 
            0, null, null, 0, 0, null, null, 0, 
            0, null, null, 0, 0, null, null, 0]
 */
//[0, 0, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0,0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, 0, null, null, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0,0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0, 0, null, null, 0]
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
