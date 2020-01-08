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
    vector<TreeNode*> build(int l, int r){
        if(l > r) return vector<TreeNode*>{NULL};
        vector<TreeNode*> ans;
        for (int i = l; i <= r; ++i){
            vector<TreeNode*> ll = build(l, i - 1);
            vector<TreeNode*> rr = build(i + 1, r);
            for (TreeNode* left: ll)
                for (TreeNode* right: rr){
                    TreeNode* root = new TreeNode(i);
                    root->left = left, root->right = right;
                    ans.push_back(root);
                }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) { 
        if (!n) return vector<TreeNode*>();
        return build(1, n);
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
