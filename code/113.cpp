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
    vector<int> ss;
    vector<vector<int> > ans;
    void dfs(TreeNode* root, int sum, int left){
        ss.push_back(root->val);
        left += root->val;
        if(root->left == NULL){
            if(root->right != NULL)
                dfs(root->right, sum, left);
            else{
                if(sum == left) ans.push_back(ss);
            }
        }else{
            dfs(root->left, sum, left);
            if(root->right != NULL)
                dfs(root->right, sum, left);
        }
        ss.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root != NULL)
            dfs(root, sum, 0);
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
