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
    bool isLeaf(TreeNode* root) {
        return root->left == NULL && root->right == NULL;
    }
    typedef pair<TreeNode*, int> pp;
    pp lca(TreeNode* root, int dep) {
        if(root->left == NULL){
            if(root->right == NULL){
                return make_pair(root, dep);
            }else{
                pp res = lca(root->right, dep + 1);
                return res;
            }
        }else{
            if(root->right == NULL){
                pp res = lca(root->left, dep + 1);
                return res;
            }else{
                pp resl = lca(root->left, dep + 1);
                pp resr = lca(root->right, dep + 1);
                if (isLeaf(root->left)){
                    if(isLeaf(root->right))
                        return make_pair(root, dep + 1);
                    return resr;
                }else{
                    if(isLeaf(root->right))
                        return resl;
                    if(resl.second > resr.second) return resl;
                    else if(resl.second < resr.second) return resr;
                    return make_pair(root, resr.second);
                }
            }
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return lca(root, 1).first;
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
