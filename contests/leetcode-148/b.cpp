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
    int lnum, rnum;
    int getW(TreeNode* root){
        if (root == NULL) return 0;
        return 1 + getW(root->left) + getW(root->right);
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if (root == NULL) return false;
        if (root->val == x){
            lnum = getW(root->left), rnum = getW(root->right);
            int res = n - 1 - lnum - rnum;
            return (res > lnum + rnum + 1 || lnum > res + rnum + 1 || rnum > res + lnum + 1);
        }else {
            return btreeGameWinningMove(root->left, n, x) || btreeGameWinningMove(root->right, n, x);
        }
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
