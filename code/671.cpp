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
    unsigned int fun(TreeNode* root) {
        if(root == NULL) return 2147483648u;
        if(root->left != NULL){
            if(root->left->val == root->right->val){
                if(root->val == root->left->val){
                    unsigned int res1 = fun(root->left);
                    unsigned int res2 = fun(root->right);
                    int res = min(res1, res2);
                    if(res == root->val) {
                        int rres = max(res1, res2);
                        return rres == root->val ? 2147483648u: rres;
                    }else return res;
                }else{
                    return root->left->val;
                }
            }else{
                if(root->val == root->left->val){
                    unsigned int res1 = fun(root->left);
                    if(res1 == root->val) return root->right->val;
                    return min(res1, (unsigned int)root->right->val);
                }else if(root->val == root->right->val){
                    unsigned int res1 = fun(root->right);
                    if(res1 == root->val) return root->left->val;
                    return min(res1, (unsigned int)root->left->val);
                }else return min(root->left->val, root->right->val);
            }
        }else return 2147483648u;
    }
    int findSecondMinimumValue(TreeNode* root) {
        unsigned int ans = fun(root);
        return ans == 2147483648u ? -1: ans;
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
