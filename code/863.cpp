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
    unordered_map<int, int> step;
    TreeNode* targ;
    int ddep;
    vector<int> ans;
    bool getH(TreeNode* root){
        if (root == NULL) return false;
        if (root == targ) {
            step[root->val] = 0;
            return true;
        }
        if (getH(root->left)){
            step[root->val] = step[root->left->val] + 1;
            return true;
        }else if (getH(root->right)){
            step[root->val] = step[root->right->val] + 1;
            return true;
        }else return false;
    }
    void getAns(TreeNode* root){
        int mystep = step[root->val];
        if (mystep == ddep) ans.push_back(root->val);
        if (root->left != NULL){
            if (!step.count(root->left->val)) 
                step[root->left->val] = step[root->val] + 1;
            getAns(root->left);
        }
        if (root->right != NULL){
            if (!step.count(root->right->val)) 
                step[root->right->val] = step[root->val] + 1;
            getAns(root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (!K) return vector<int>{target->val};
        targ = target, ddep = K;
        getH(root), getAns(root);
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
