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
    pair<pair<int, int>, int> dfs(TreeNode* root) {
        int f0 = 0x3f3f3f3f, f1 = 0x3f3f3f3f, f2 = 0;
        if(root->left != NULL){
            auto fl = dfs(root->left);
            if(root->right != NULL){
                auto fr = dfs(root->right);
                f0 = min(fl.first.first + fr.first.second, fl.first.second + fr.first.first);
                f0 = min(f0, fl.first.second + fr.first.second);
                int t1 = min(fl.first.first, fl.first.second), t2 = min(fr.first.second, fr.first.first); 
                f1 = min(fl.second, t1) + min(fr.second, t2) + 1;
                f2 = t1 + t2;
            }else{
                f0 = fl.first.second;
                f2 = min(fl.first.first, fl.first.second);
                f1 = min(fl.second, f2) + 1;
            }
        }else{
            if(root->right != NULL){
                auto fr = dfs(root->right);
                f0 = fr.first.second;
                f2 = min(fr.first.second, fr.first.first);
                f1 = min(fr.second, f2) + 1;
            }else{
                f1 = 1;
            }
        }
        return make_pair(make_pair(f0, f1), f2);
    }
    int minCameraCover(TreeNode* root) {
        if(root == NULL) return 0;
        pair<pair<int, int>, int> ans = dfs(root);
        return min(ans.first.first, ans.first.second);
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
