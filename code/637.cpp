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
    vector<int> cnt;
    vector<double> ans;
    void dfs( TreeNode* root, int dep ){
        if ( root == NULL ) return ;
        if ( dep > cnt.size() )
            cnt.push_back( 1 ), ans.push_back( root->val );
        else ++cnt[dep - 1], ans[dep - 1] += root->val;
        dfs( root->left, dep + 1 );
        dfs( root->right, dep + 1 );
    }
    vector<double> averageOfLevels(TreeNode* root) {
        dfs( root, 1 );
        for (int i = 0; i < cnt.size(); ++i)
            ans[i] /= 1.0 * cnt[i];
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
