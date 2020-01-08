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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(root == NULL) return ans;
        queue<TreeNode *> q;
        int hd = 0, tl = 1, lsttl = 0;
        q.push(root);
        while(tl > lsttl){
            ans.push_back(vector<int>());
            lsttl = tl;
            while(hd < lsttl){
                TreeNode *t = q.front();
                q.pop(), hd++;
                ans.back().push_back(t->val);
                if(t->left != NULL) q.push(t->left), tl++;
                if(t->right != NULL) q.push(t->right), tl++;
            }
        }
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
