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
    vector<int> ans;
    int cnt, cur, ans_cnt;
    void dfs(TreeNode* root){
        if (root == NULL) return ;
        dfs(root->left);
        if (cur == root->val){
            ++cnt;
        }else{
            if (cnt == ans_cnt) ans.push_back(cur);
            else if (cnt > ans_cnt){
                ans_cnt = cnt;
                ans = vector<int>{cur};
            }
            cnt = 1, cur = root->val;
        }
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        if (root == NULL) return ans;
        cnt = 0, cur = -1, ans_cnt = 0;
        dfs(root);
        if (cnt == ans_cnt){
            ans.push_back(cur);
        }else if (cnt > ans_cnt) {
            return vector<int>{cur};
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
